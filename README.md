This is a excavator project.

# Quick Start
if using localhost:

unset ROS_MASTER_URI ROS_IP ROS_HOSTNAME

# Auto bringup+gmapping+RGBD+rviz
roslaunch clbrobot blended_slam.launch 

# Single Tasks
## bringup
roslaunch clbrobot bringup.launch

## Arm control
roslaunch excavator_controller excavator_melodic.launch  

## SLAM
roslaunch clbrobot lidar_slam.launch

## Camera
roslaunch astra_launch astra.launch
