findLCMTypes(os.path.expanduser('~/code/kuka-dev/drake/build/drake/lcmtypes/drake'))

def positions_measured_s(idx):
	# convert time from nano seconds to milliseconds
	f = lambda msg: (int(msg.timestamp*1000), msg.joint_position_measured[idx])
	return f

def desired_position_command_s(idx):
	# convert time from nano seconds to milliseconds
	f = lambda msg: (int(msg.timestamp*1000), msg.coefficients[idx])
	return f

for i in range(7):
	addPlot()
	addSignalFunction('IIWA_PARAM', desired_position_command_s(i))
	addSignalFunction('IIWA_STATUS', positions_measured_s(i))