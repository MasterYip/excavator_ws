This is a excavator project.

# Quick Start
if using localhost:
```
unset ROS_MASTER_URI ROS_IP ROS_HOSTNAME
```

## bringup
```
roslaunch clbrobot bringup.launch
```

## Arm control
```
roslaunch excavator_controller excavator_melodic.launch  
```
## SLAM
'''
roslaunch clbrobot lidar_slam.launch
'''