findLCMTypes(os.path.expanduser('~/code/kuka-dev/drake/build/drake/lcmtypes/drake'))

def feedforward_torque_command_s(idx):
	# convert time from nano seconds to milliseconds
	f = lambda msg: (int(msg.timestamp*1000), msg.coefficients[idx])
	return f

def feedback_PD_torque_command_s(idx):
	# convert time from nano seconds to milliseconds
	f = lambda msg: (int(msg.timestamp*1000), msg.q_des[idx])
	return f

addPlot()
addSignalFunction('IIWA_PARAM', feedforward_torque_command_s(0))
addSignalFunction('IIWA_PARAM2', feedback_PD_torque_command_s(0))

addPlot()
addSignalFunction('IIWA_PARAM', feedforward_torque_command_s(1))
addSignalFunction('IIWA_PARAM2', feedback_PD_torque_command_s(1))

addPlot()
addSignalFunction('IIWA_PARAM', feedforward_torque_command_s(2))
addSignalFunction('IIWA_PARAM2', feedback_PD_torque_command_s(2))

addPlot()
addSignalFunction('IIWA_PARAM', feedforward_torque_command_s(3))
addSignalFunction('IIWA_PARAM2', feedback_PD_torque_command_s(3))

addPlot()
addSignalFunction('IIWA_PARAM', feedforward_torque_command_s(4))
addSignalFunction('IIWA_PARAM2', feedback_PD_torque_command_s(4))

addPlot()
addSignalFunction('IIWA_PARAM', feedforward_torque_command_s(5))
addSignalFunction('IIWA_PARAM2', feedback_PD_torque_command_s(5))

addPlot()
addSignalFunction('IIWA_PARAM', feedforward_torque_command_s(6))
addSignalFunction('IIWA_PARAM2', feedback_PD_torque_command_s(6))

