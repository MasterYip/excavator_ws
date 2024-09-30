# Excavator Operation System

Excavator workspace for Sany excavator robot model.

<!-- Video -->
<!-- <video src="doc/excavator_op.mp4" width="320" height="200" controls preload></video> -->
<!-- <div class="columns is-centered">
    <div class="column content">
        <video id="matting-video" autoplay controls muted loop playsinline height="100%">
            <source src="./doc/excavator_op.mp4" type="video/mp4">
        </video>
    </div>
</div> -->

<!-- <div style="text-align: center;">
  <video width="600" controls>
    <source src="doc/excavator_op.mp4" type="video/mp4">
  </video>
</div> -->

<div style="text-align: center;">
  <iframe width="560" height="315" src="https://github.com/MasterYip/excavator_ws/blob/using_ros_control/doc/excavator_op.mp4" frameborder="0" allowfullscreen></iframe>
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
