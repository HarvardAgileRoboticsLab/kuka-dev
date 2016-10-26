findLCMTypes(os.path.expanduser('~/code/kuka-dev/drake/build/drake/lcmtypes/drake'))

def positions_measured_s(idx):
	# convert time from nano seconds to milliseconds
	f = lambda msg: (int(msg.timestamp*1000), msg.joint_position_measured[idx])
	return f

def velocities_estimated_s(idx):
	# convert time from nano seconds to milliseconds
	f = lambda msg: (int(msg.timestamp*1000), msg.joint_velocity_estimated[idx])
	return f

addPlot()
# add all seven position measurements
for i in range(7):
	addSignalFunction('IIWA_STATUS', positions_measured_s(i))

addPlot()
# add all seven position measurements
for i in range(7):
	addSignalFunction('IIWA_STATUS', velocities_estimated_s(i))

