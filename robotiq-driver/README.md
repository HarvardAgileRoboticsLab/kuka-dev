# robotiq

1)To connect to robotiq hand, ensure your FTDI drivers are up to date, and connect it to usb. 
2)Connect power to a 24V power supply, and turn it on (Robotiq hand should light up bluish and then go to solid red)
3)Check which TTY the robotiq is connected to with dmesg and then run:   
sudo python CModelRtuNode.py /dev/ttyUSB0
4)The light on the robotiq hand should turn blue,indicating that it is connected
5)Run:
python CModelSimpleController.py.

Right now, this driver can be run in Director as an alternative way (integrated with the kuka arm). For more details, please check HarvardAgileRoboticsLab/drake kuka-dev branch. Run the following command to launch the procman in drake directory
build/install/bin/bot-procman-sheriff -l ./drake/examples/kuka_iiwa_arm/kuka_torque_control.pmd. 
Launch the Director and control the gripper by using gripper buttons in Director.

