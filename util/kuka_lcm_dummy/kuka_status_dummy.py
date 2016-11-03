import lcm
# from drake import lcmt_iiwa_status
from lcmt_iiwa_status import lcmt_iiwa_status
import time, math, random

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
  msg.joint_torque_external = [random.random() for _ in range(7)]
  msg.joint_torque_commanded = [random.random() for _ in range(7)]
  msg.joint_torque_measured = [random.random() for _ in range(7)]
  msg.joint_position_ipo = [random.random() for _ in range(7)]  

  lc.publish("IIWA_STATUS", msg.encode())
  # publish at 20Hz
  time.sleep(0.05)