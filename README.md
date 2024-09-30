# Excavator Operation System

Excavator workspace for Sany excavator robot model.

<!-- Video -->
<div style="display:flex; justify-content:center; text-align: center;">
  <video src="https://github.com/user-attachments/assets/c59453cb-190a-4602-b985-3f2bf36b121a" width="320" height="200" controls preload></video>
</div>
<br />

<div style="display:flex; justify-content:center; text-align: center;">
    <img src="https://github.com/user-attachments/assets/eb50783f-feac-4404-b666-03ac5298e89d" alt="Image 1" style="height:300px; margin-right:10px;"/>
</div>
<div style="display:flex; justify-content:center; text-align: center;">
    Diagram of Excavator Operation System
</div>


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
