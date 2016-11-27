# findLCMTypes(os.path.expanduser('~/code/kuka-dev/drake/build/drake/lcmtypes/drake'))
lcm_dir = os.path.abspath(os.path.join(__file__,'..','..','..',
                    'drake','build','drake','lcmtypes','drake'))
findLCMTypes(lcm_dir)

def positions_measured(msg):
  '''measured positions'''
  # convert time from nano seconds to milliseconds
  return int(msg.timestamp*1000), msg.joint_position_measured

def velocities_estimated(msg):
  '''measured velocities'''
  # convert time from nano seconds to milliseconds
  return int(msg.timestamp*1000), msg.joint_velocity_estimated

addPlot()
# add all seven position measurements
addSignalFunctions('IIWA_STATUS', positions_measured, range(7))

addPlot()
# add all seven velocity estimated
addSignalFunctions('IIWA_STATUS', velocities_estimated, range(7))

