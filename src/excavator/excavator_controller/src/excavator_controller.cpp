#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <control_msgs/FollowJointTrajectoryAction.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <sensor_msgs/JointState.h>
#include <std_msgs/Float32MultiArray.h>
using namespace std;

class JointTrajectoryActionServer
{
protected:
ros::NodeHandle nh_;
ros::Publisher pub = nh_.advertise<sensor_msgs::JointState>("target_joint_state", 1000);
actionlib::SimpleActionServer<control_msgs::FollowJointTrajectoryAction> as_;
actionlib::SimpleActionServer<control_msgs::FollowJointTrajectoryAction>::Result result_;
std::string action_name_;

public:
// void Data_formatter(const sensor_msgs::JointState *data)
// {
// 	data->
// }


JointTrajectoryActionServer(std::string name) :
as_(nh_, name, boost::bind(&JointTrajectoryActionServer::goalCallback, this, _1), false),
action_name_(name)
{
	as_.start();
}

~JointTrajectoryActionServer(void){}

// when a trajectory command comes, this function will be called.
void goalCallback(const control_msgs::FollowJointTrajectoryGoalConstPtr& goal)
{
	bool success = true;
	ros::Rate action_rate(20);
	//此处修改了源码 由 FollowJointTrajectoryGoal 改为 FollowJointTrajectoryActionGoal不知是否合理
	// boost::shared_ptr<const control_msgs::FollowJointTrajectoryGoal> goal;
	sensor_msgs::JointState target_joint_state;
	int point_count = 0;
	int point_size = goal->trajectory.points.size();
	//赋予初值 使得容器可被下标检索
	target_joint_state.name.assign(
		goal->trajectory.joint_names.begin(),
		goal->trajectory.joint_names.end());
	target_joint_state.position.assign(
		goal->trajectory.points[point_count].positions.begin(),
		goal->trajectory.points[point_count].positions.end());
	target_joint_state.velocity.assign(
		goal->trajectory.points[point_count].velocities.begin(),
		goal->trajectory.points[point_count].velocities.end());
	target_joint_state.effort.assign(
		goal->trajectory.points[point_count].effort.begin(),
		goal->trajectory.points[point_count].effort.end());

	//接受任务目标？
	// goal=as_.acceptNewGoal();
	ROS_INFO("trajectory point size:%d\n", point_size);
	ros::Time action_start_time = ros::Time::now();

	while(point_count < point_size)
	{
		// tell motion control hardware to execute
		// do something
		// when finished, return result
		if (as_.isPreemptRequested() || !ros::ok())
		{
			ROS_INFO("%s: Preempted", action_name_.c_str());
			as_.setPreempted();
			success = false;
			break;
		}

		while(ros::Time::now()-action_start_time > goal->trajectory.points[point_count].time_from_start)
		{
			point_count++;
		}
		//防止下标越界
		if(point_count >= point_size) break;

		ROS_INFO("trajectory point now:%d\n", point_count);

		target_joint_state.header.stamp = ros::Time::now();
		target_joint_state.header.seq = point_count;

		for(int cnt=0; cnt<4; cnt++)
		{
			// ROS_INFO(goal->trajectory.joint_names[cnt]);
			if(goal->trajectory.joint_names[cnt] == "table_joint")
			{
				target_joint_state.name[0] = goal->trajectory.joint_names[cnt];
				target_joint_state.position[0] = goal->trajectory.points[point_count].positions[cnt];
				target_joint_state.velocity[0] = goal->trajectory.points[point_count].velocities[cnt];
			}
			else if(goal->trajectory.joint_names[cnt] == "link1_joint")
			{
				target_joint_state.name[1] = goal->trajectory.joint_names[cnt];
				target_joint_state.position[1] = goal->trajectory.points[point_count].positions[cnt];
				target_joint_state.velocity[1] = goal->trajectory.points[point_count].velocities[cnt];
			}
			else if(goal->trajectory.joint_names[cnt] == "link2_joint")
			{
				target_joint_state.name[2] = goal->trajectory.joint_names[cnt];
				target_joint_state.position[2] = goal->trajectory.points[point_count].positions[cnt];
				target_joint_state.velocity[2] = goal->trajectory.points[point_count].velocities[cnt];
			}
			else if(goal->trajectory.joint_names[cnt] == "ram_joint")
			{
				target_joint_state.name[3] = goal->trajectory.joint_names[cnt];
				target_joint_state.position[3] = goal->trajectory.points[point_count].positions[cnt];
				target_joint_state.velocity[3] = goal->trajectory.points[point_count].velocities[cnt];
			}
			
		}
		
		pub.publish(target_joint_state);
		action_rate.sleep();
	}

	if(success)
    {
		result_.error_code = 0;
		ROS_INFO("%s: Succeeded", action_name_.c_str());
		// set the action state to succeeded
		as_.setSucceeded(result_);
    }
}

};

int main(int argc, char** argv)
{
	ros::init(argc,argv, "excavator_controller");
	JointTrajectoryActionServer srv("excavator_controller/follow_joint_trajectory");
    ROS_INFO("I'm HERE!!\n");
	ros::spin();
	return 0;
}