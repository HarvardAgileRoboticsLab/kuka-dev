findLCMTypes(os.path.expanduser('~/code/kuka-dev/drake/build/drake/lcmtypes/drake'))

def positions_measured_s(idx):
	# convert time from nano seconds to milliseconds
	f = lambda msg: (int(msg.timestamp*1000), msg.joint_position_measured[idx])
	return f

def positions_commanded_s(idx):
	# convert time from nano seconds to milliseconds
	f = lambda msg: (int(msg.timestamp*1000), msg.joint_position_commanded[idx])
	return f

def velocities_estimated_s(idx):
	# convert time from nano seconds to milliseconds
	f = lambda msg: (int(msg.timestamp*1000), msg.joint_velocity_estimated[idx])
	return f

def torque_measured_s(idx):
	# convert time from nano seconds to milliseconds
	f = lambda msg: (int(msg.timestamp*1000), msg.joint_torque_measured[idx])
	return f

def torque_commanded_s(idx):
	# convert time from nano seconds to milliseconds
	f = lambda msg: (int(msg.timestamp*1000), msg.joint_torque_commanded[idx])
	return f

def real_torque_commanded_s(idx):
	# convert time from nano seconds to milliseconds
	f = lambda msg: (int(msg.timestamp*1000), msg.joint_torque[idx])
	return f

def real_position_commanded_s(idx):
	# convert time from nano seconds to milliseconds
	f = lambda msg: (int(msg.timestamp*1000), msg.joint_position[idx])
	return f

def computed_torque_command_s(idx):
	# convert time from nano seconds to milliseconds
	f = lambda msg: (int(msg.timestamp*1000), msg.coefficients[idx])
	return f

addPlot()
# add all seven position measurements
for i in range(7):
	# addSignalFunction('IIWA_STATUS', velocities_estimated_s(i))
	addSignalFunction('IIWA_STATUS', torque_measured_s(i))
	addSignalFunction('IIWA_STATUS', torque_commanded_s(i))
	
# addPlot()
# # add all seven position measurements
# for i in range(7):
# 	# addSignalFunction('IIWA_STATUS', velocities_estimated_s(i))
# 	addSignalFunction('IIWA_PARAM', computed_torque_command_s(i))
# 	#addSignalFunction('IIWA_STATUS', real_torque_commanded_s(i))
