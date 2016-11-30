findLCMTypes(os.path.expanduser('~/code/kuka-dev/drake/build/drake/lcmtypes/drake'))


for i in range(7):
	addPlot()
	addSignal('IIWA_COMMAND', msg.utime, msg.joint_position[i])
	addSignal('IIWA_STATUS', msg.utime, msg.joint_position_measured[i])