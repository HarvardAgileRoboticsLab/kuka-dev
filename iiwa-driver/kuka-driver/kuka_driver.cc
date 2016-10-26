
#include <cassert>
#include <cmath>
#include <cstring>

#include <iostream>
#include <limits>
#include <stdexcept>

#include <lcm/lcm-cpp.hpp>

#include "friClientApplication.h"
#include "friLBRClient.h"
#include "friUdpConnection.h"

#include "lcmtypes/drake/lcmt_iiwa_command.hpp"
#include "lcmtypes/drake/lcmt_iiwa_status.hpp"

namespace drake {
namespace examples {
namespace kuka_iiwa_arm {
namespace {

const char* lcm_status_channel = "IIWA_STATUS";
const char* lcm_command_channel = "IIWA_COMMAND";
const float alpha = 0.6;

double ToRadians(double degrees) {
  return degrees * M_PI / 180.;
}

class KukaLCMClient : public KUKA::FRI::LBRClient {
 public:
  KukaLCMClient() {
    // Use -1 as a sentinal to indicate that no status has been
    // sent (or received from the robot).
    lcm_status_.timestamp = -1;
    lcm_status_.num_joints = num_joints_;
    lcm_status_.joint_position_measured.resize(num_joints_);
    lcm_status_.joint_position_commanded.resize(num_joints_);
    lcm_status_.joint_position_ipo.resize(num_joints_);
    lcm_status_.joint_velocity_estimated.resize(num_joints_);
    lcm_status_.joint_torque_measured.resize(num_joints_);
    lcm_status_.joint_torque_commanded.resize(num_joints_);
    lcm_status_.joint_torque_external.resize(num_joints_);

    // Use -1 as a sentinal to indicate that no command has been
    // received.
    lcm_command_.timestamp = -1;

    // Joint limits derived from visual inspection of KUKA controller
    // output display.  Values in +/- degrees from center.
    joint_limits_.push_back(ToRadians(170));
    joint_limits_.push_back(ToRadians(120));
    joint_limits_.push_back(ToRadians(170));
    joint_limits_.push_back(ToRadians(120));
    joint_limits_.push_back(ToRadians(170));
    joint_limits_.push_back(ToRadians(120));
    joint_limits_.push_back(ToRadians(175));

    lcm_.subscribe(lcm_command_channel,
                   &KukaLCMClient::HandleCommandMessage, this);
  }

  ~KukaLCMClient() {}

  virtual void onStateChange(KUKA::FRI::ESessionState oldState,
                             KUKA::FRI::ESessionState newState) {
    KUKA::FRI::LBRClient::onStateChange(oldState, newState);

    const KUKA::FRI::LBRState& state = robotState();
    const uint64_t time = state.getTimestampSec() * 1e3 +
        state.getTimestampNanoSec() / 1e6;
    std::cerr << "onStateChange ( " << time << "): old " << oldState
              << " new " << newState << std::endl;

    std::cerr << "onStateChange ( " << time
              << "): quality " << state.getConnectionQuality()
              << " safety " << state.getSafetyState()
              << " oper " << state.getOperationMode()
              << " drive " << state.getDriveState()
              << " control " << state.getControlMode()
              << " command " << state.getClientCommandMode()
              << " overlay " << state.getOverlayType()
              << std::endl;

  }

  virtual void monitor() {
    KUKA::FRI::LBRClient::monitor();
    PublishStateUpdate();
  }

  virtual void waitForCommand() {
    KUKA::FRI::LBRClient::waitForCommand();

    // The value of the torques sent in waitForCommand doesn't matter,
    // but we have to send something.
    if (robotState().getClientCommandMode() == KUKA::FRI::TORQUE) {
      double torque[num_joints_] = { 0., 0., 0., 0., 0., 0., 0.};
      robotCommand().setTorque(torque);
    }

    PublishStateUpdate();
  }
  virtual void command() {
    PublishStateUpdate();

    if (lcm_status_.timestamp == -1) {
      return;
    }

    double pos[num_joints_] = { 0., 0., 0., 0., 0., 0., 0.};
    if (lcm_command_.timestamp == -1) {
      // No command received, just command the current position.
      memcpy(pos, lcm_status_.joint_position_measured.data(),
             num_joints_ * sizeof(double));
    } else {
      assert(lcm_command_.num_joints == num_joints_);
      memcpy(pos, lcm_command_.joint_position.data(),
             num_joints_ * sizeof(double));
    }
    ApplyJointLimits(pos);
    robotCommand().setJointPosition(pos);

    // Check if we're in torque mode, and send torque commands too if
    // we are.
    if (robotState().getClientCommandMode() == KUKA::FRI::TORQUE) {
      double torque[num_joints_] = { 0., 0., 0., 0., 0., 0., 0.};
      if (lcm_command_.timestamp != -1) {
        if (lcm_command_.num_torques != num_joints_) {
          throw std::runtime_error(
              "No torque values specified (or incorrect number) "
              "while in torque command mode.");
        }
        memcpy(torque, lcm_command_.joint_torque.data(),
               num_joints_ * sizeof(double));
      }
      // TODO(sam.creasey): Is there a sensible torque limit to apply here?
      robotCommand().setTorque(torque);
    } else {
      if (lcm_command_.timestamp != -1 && lcm_command_.num_torques != 0) {
        throw std::runtime_error(
            "Torque values specified when not in torque command mode.");
      }
    }
  }

 private:
  void ApplyJointLimits(double* pos) const {
      const double joint_tol = ToRadians(5);
      for (int i = 0; i < num_joints_; i++) {
        pos[i] = std::max(std::min(pos[i], (joint_limits_[i] - joint_tol)),
                          ((-joint_limits_[i]) + joint_tol));
      }
  }

  void HandleCommandMessage(const lcm::ReceiveBuffer* rbuf,
                            const std::string& chan,
                            const lcmt_iiwa_command* command) {
    lcm_command_ = *command;
  }

  void UpdateJointVelocityEstimate() {
    double delta_pos, dt;
    for (int i=0; i<num_joints_; i++) {
      delta_pos = lcm_status_.joint_position_measured[i] - joint_position_previous_[i];
      dt = double(lcm_status_.timestamp - timestamp_previous_)/1e3;
      joint_velocity_estimate_[i] = (1-alpha) * joint_velocity_estimate_[i] + alpha* delta_pos/dt;
    } 
    std::memcpy(lcm_status_.joint_velocity_estimated.data(),
                joint_velocity_estimate_.data(), num_joints_ * sizeof(double));
  }

  void PublishStateUpdate() {
    const KUKA::FRI::LBRState& state = robotState();

    lcm_status_.timestamp = state.getTimestampSec() * 1e3 +
        state.getTimestampNanoSec() / 1e6;
    std::memcpy(lcm_status_.joint_position_measured.data(),
                state.getMeasuredJointPosition(), num_joints_ * sizeof(double));
    std::memcpy(lcm_status_.joint_position_commanded.data(),
                state.getCommandedJointPosition(), num_joints_ * sizeof(double));
    if (state.getIpoJointPosition() != NULL) {
      std::memcpy(lcm_status_.joint_position_ipo.data(),
                  state.getIpoJointPosition(), num_joints_ * sizeof(double));
    } else {
      lcm_status_.joint_position_ipo.assign(
          num_joints_, std::numeric_limits<double>::quiet_NaN());

    }
    std::memcpy(lcm_status_.joint_torque_measured.data(),
                state.getMeasuredTorque(), num_joints_ * sizeof(double));
    std::memcpy(lcm_status_.joint_torque_commanded.data(),
                state.getCommandedTorque(), num_joints_ * sizeof(double));
    std::memcpy(lcm_status_.joint_torque_external.data(),
                state.getExternalTorque(), num_joints_ * sizeof(double));

    if (joint_position_previous_.empty()) {
      // init velocity estimator
      joint_position_previous_.resize(num_joints_);
      for (int i=0; i<num_joints_; i++) {
        joint_velocity_estimate_.push_back(0);
      }
    }
    else {
      UpdateJointVelocityEstimate();
    }
    std::memcpy(joint_position_previous_.data(),
                state.getMeasuredJointPosition(), num_joints_ * sizeof(double));
    timestamp_previous_ = lcm_status_.timestamp;



    lcm_.publish(lcm_status_channel, &lcm_status_);
    // Also poll for new messages.
    lcm_.handleTimeout(0);
  }

  static const int num_joints_ = 7;

  lcm::LCM lcm_;
  lcmt_iiwa_status lcm_status_;
  lcmt_iiwa_command lcm_command_;
  std::vector<double> joint_limits_;
  std::vector<double> joint_velocity_estimate_;
  std::vector<double> joint_position_previous_;
  long timestamp_previous_;
};

int do_main(int argc, const char* argv[]) {
  KUKA::FRI::UdpConnection connection;
  KukaLCMClient client;
  KUKA::FRI::ClientApplication app(connection, client);

  // TODO(sam.creasey) make host/port configurable
  const int default_port = 30200;
  app.connect(default_port, NULL);

  bool success = true;
  while (success) {
    success = app.step();
  }
  app.disconnect();

  return 0;
}

} // namespace
} // namespace kuka_iiwa_arm
} // namespace examples
} // namespace drake

int main(int argc, const char* argv[]) {
  return drake::examples::kuka_iiwa_arm::do_main(argc, argv);
}
