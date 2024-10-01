# Excavator Operation System

Excavator workspace for Sany excavator robot model.

<!-- Video -->
<p align="center">
    <video src="https://github.com/user-attachments/assets/c59453cb-190a-4602-b985-3f2bf36b121a" width="200" height="100" autoplay controls muted loop playsinline></video>
</p>
<br />

<p align="center">
    <img src="https://github.com/user-attachments/assets/eb50783f-feac-4404-b666-03ac5298e89d" alt="Image 1" style="width:800px"/>

</p>
<p align="center">
Diagram of Excavator Operation System
</p>

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
