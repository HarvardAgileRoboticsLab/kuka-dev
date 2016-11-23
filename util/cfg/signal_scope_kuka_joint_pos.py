findLCMTypes(os.path.expanduser('~/code/kuka-dev/drake/build/drake/lcmtypes/drake'))

def positions_measured_s(idx):
	# convert time from nano seconds to milliseconds
	f = lambda msg: (int(msg.timestamp*1000), msg.joint_position_measured[idx])
	return f

def desired_position_command_s(idx):
	# convert time from nano seconds to milliseconds
	f = lambda msg: (int(msg.timestamp*1000), msg.coefficients[idx])
	return f

#addPlot(timeWindow=15, yLimits=[-3.14, 3.14])
# addPlot()
# addSignals('IIWA_PARAM', msg.utime, msg.desired_position_command_s, range(7))
# addSignals('IIWA_STATUS', msg.utime, msg.positions_measured_s, range(7))

addPlot()
addSignalFunction('IIWA_PARAM', desired_position_command_s(0))
addSignalFunction('IIWA_STATUS', positions_measured_s(0))

addPlot()
addSignalFunction('IIWA_PARAM', desired_position_command_s(1))
addSignalFunction('IIWA_STATUS', positions_measured_s(1))

addPlot()
addSignalFunction('IIWA_PARAM', desired_position_command_s(2))
addSignalFunction('IIWA_STATUS', positions_measured_s(2))

addPlot()
addSignalFunction('IIWA_PARAM', desired_position_command_s(3))
addSignalFunction('IIWA_STATUS', positions_measured_s(3))

addPlot()
addSignalFunction('IIWA_PARAM', desired_position_command_s(4))
addSignalFunction('IIWA_STATUS', positions_measured_s(4))

addPlot()
addSignalFunction('IIWA_PARAM', desired_position_command_s(5))
addSignalFunction('IIWA_STATUS', positions_measured_s(5))

addPlot()
addSignalFunction('IIWA_PARAM', desired_position_command_s(6))
addSignalFunction('IIWA_STATUS', positions_measured_s(6))

