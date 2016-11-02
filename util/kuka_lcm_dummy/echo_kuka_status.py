import lcm
from lcmt_iiwa_status import lcmt_iiwa_status

def handler(channel, data):
  msg = lcmt_iiwa_status.decode(data)
  print "Received message on channel %s" % (channel,)
  print "Timestamp: ", msg.timestamp
  print "Position Measured: ", msg.joint_position_measured
  print "Velocity Estimated: ", msg.joint_velocity_estimated, "\n"

lc = lcm.LCM()
sub = lc.subscribe("IIWA_STATUS", handler)

while True:
  lc.handle()