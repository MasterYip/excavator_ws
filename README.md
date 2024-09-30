# Excavator Operation System
Excavator workspace for Sany excavator robot model.


## Quick Start
if using localhost:
```bash
unset ROS_MASTER_URI ROS_IP ROS_HOSTNAME
```
## Auto bringup+gmapping+RGBD+rviz
roslaunch clbrobot blended_slam.launch 

## Single Tasks
### Bring up
```bash
roslaunch clbrobot bringup.launch
```
### Arm control
```bash
roslaunch excavator_controller excavator_melodic.launch  
```
### Gazebo Sim
#### Gazebo only
```bash
roslaunch excavator_gazebo view_excavator_empty_world.launch
```
#### Gazebo & Moveit
```bash
roslaunch excavator_moveit_config demo_gazebo.launch
```
### SLAM
```bash
roslaunch clbrobot lidar_slam.launch
```
### Camera
```bash
roslaunch astra_launch astra.launch
```
