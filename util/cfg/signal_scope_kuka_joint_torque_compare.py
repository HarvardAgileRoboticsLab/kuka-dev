findLCMTypes(os.path.expanduser('~/code/kuka-dev/drake/build/drake/lcmtypes/drake'))

def feedforward_torque_command_s(idx):
	# convert time from nano seconds to milliseconds
	f = lambda msg: (int(msg.timestamp*1000), msg.coefficients[idx])
	return f

def feedback_PD_torque_command_s(idx):
	# convert time from nano seconds to milliseconds
	f = lambda msg: (int(msg.timestamp*1000), msg.q_des[idx])
	return f

for i in range(7):
	addPlot()
	addSignalFunction('IIWA_PARAM', feedforward_torque_command_s(i))
	addSignalFunction('IIWA_PARAM2', feedback_PD_torque_command_s(i))
