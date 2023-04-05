<!--
 * @Author: Raymon Yip 2205929492@qq.com
 * @Date: 2023-04-04 18:27:14
 * @LastEditors: Raymon Yip 2205929492@qq.com
 * @LastEditTime: 2023-04-04 20:34:28
 * @FilePath: /excavator_ws/README.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
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

## Gazebo Sim
### Gazebo only
roslaunch excavator_gazebo view_excavator_empty_world.launch
### Gazebo & Moveit
roslaunch excavator_moveit_config demo_gazebo.launch

## SLAM
roslaunch clbrobot lidar_slam.launch

## Camera
roslaunch astra_launch astra.launch
