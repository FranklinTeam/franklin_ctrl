# franklin_ctrl
Control package for the turtlebot3 franklin project, contains the simulink models

This package is the only one recquired on every turtlebot3 and not on the remote PC.

If you want to simulate turtlebots, you need to install this on your remote PC

# Requirements
- Ubuntu 16.04
- Gazebo (Simulation only)
- RViz
- QTCreator
- Matlab / Simulink (Robotic Toolbox & Matlab Compiler & its requirements)

# Install

1. Make sure ROS and catkin are installed on your machine
2. Install the turtlbot3 package from robotis by following this tutorial : https://emanual.robotis.com/docs/en/platform/turtlebot3/setup/#setup
3. Once Turtlebot3 is working, add this package to ROS (src file)
4. If you want to use embedded camera you need to install OpenCV https://www.pyimagesearch.com/2018/08/15/how-to-install-opencv-4-on-ubuntu/
If you don't want to, delete the parking node
5. Try to catkin_make, if some packages are missing, download them to your src file

# Compile Simulink Models

1. If you have modifed the models, re-compile with simulink coder
2. Now you should have 2 files : an archive containing the models and a bash file
3. Run the bash file in a terminal, it will start a catkin_make to create a new node for your model
4. To run the compiled node, go to the compiled folder and run ./node_name with your node's name
