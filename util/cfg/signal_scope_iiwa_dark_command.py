# find the LCM types in the drake submodule
lcm_dir = os.path.abspath(os.path.join(__file__,'..','..','..',
                    'drake','build','drake','lcmtypes','drake'))
findLCMTypes(lcm_dir)

def torques_commanded(msg):
  '''dark torque commands'''
  # convert time from nano seconds to milliseconds
  return int(msg.timestamp*1000), msg.joint_torque

def torques_measured(msg):
  '''measured torques'''
  # convert time from nano seconds to milliseconds
  return int(msg.timestamp*1000), msg.joint_torque_measured

addPlot()
# add all seven dark torque commands
addSignalFunctions('IIWA_DARK_COMMAND', torques_commanded, range(7))

addPlot()
# add all seven torque measurements
addSignalFunctions('IIWA_STATUS', torques_measured, range(7))