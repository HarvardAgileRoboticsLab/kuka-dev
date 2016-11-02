import lcm
# from drake import lcmt_iiwa_status
from lcmt_iiwa_status import lcmt_iiwa_status
import time, math

lc = lcm.LCM()

while (True):
  t = time.time() # time in seconds

  # create a message and some sample data that varies in time
  msg = lcmt_iiwa_status()
  msg.timestamp = t*10**3 # convert to milliseconds
  msg.num_joints = 7
  msg.joint_position_commanded = [math.sin(t+.1*i) for i in range(7)]
  msg.joint_position_measured = [math.sin(t+.1*i) for i in range(7)]
  msg.joint_velocity_estimated = [math.cos(t+.1*i) for i in range(7)]
  
  # empty dummy data
  msg.joint_torque_external = [0 for _ in range(7)]
  msg.joint_torque_commanded = [0 for _ in range(7)]
  msg.joint_torque_measured = [0 for _ in range(7)]
  msg.joint_position_ipo = [0 for _ in range(7)]  

  lc.publish("IIWA_STATUS", msg.encode())
  # publish at 10Hz
  time.sleep(0.005)