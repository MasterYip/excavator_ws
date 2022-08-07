#include "ros/ros.h"
#include <sensor_msgs/JointState.h>
#include <geometry_msgs/Twist.h>


class SubscribeAndPublish  
{  
public:  
    sensor_msgs::JointState arm_state_msg;
    sensor_msgs::JointState wheel_state_msg;
    // geometry_msgs::Twist test;
    SubscribeAndPublish()  
    {  
        //Topic you want to publish  
        pub_ = n_.advertise<sensor_msgs::JointState>("joint_states", 1000); 
    
        //Topic you want to subscribe  
        sub_ = n_.subscribe("target_joint_state", 100, &SubscribeAndPublish::callback, this);  //注意这里，和平时使用回调函数不一样了。

        
        ROS_INFO("Publishing joint states");
        arm_state_msg.header.stamp = ros::Time::now();
        arm_state_msg.header.seq = 0;
        arm_state_msg.name = {"table_joint", "link1_joint", "link2_joint", "ram_joint"};
        arm_state_msg.position = {0,0,0,0};
        arm_state_msg.velocity = {0,0,0,0};
        arm_state_msg.effort = {0,0,0,0};

        wheel_state_msg.header.stamp = ros::Time::now();
        wheel_state_msg.header.seq = 0;
        wheel_state_msg.name = {"wheel1_joint", "wheel2_joint", "wheel3_joint", "wheel4_joint"};
        wheel_state_msg.position = {0,0,0,0};
        wheel_state_msg.velocity = {0,0,0,0};
        wheel_state_msg.effort = {0,0,0,0};
    }  
    
    void callback(const sensor_msgs::JointState::ConstPtr& msg)  
    {  
        // PUBLISHED_MESSAGE_TYPE output;  
        //.... do something with the input and generate the output...  

        ROS_INFO("Publishing joint states");

        arm_state_msg.header.stamp = ros::Time::now();
        arm_state_msg.header.seq ++;
        pub_.publish(*msg);  
    } 

    void pub_arm_state()
    {
        arm_state_msg.header.stamp = ros::Time::now();
        arm_state_msg.header.seq ++;
        pub_.publish(arm_state_msg);
    }

    void pub_wheel_state()
    {
        wheel_state_msg.header.stamp = ros::Time::now();
        wheel_state_msg.header.seq ++;
        pub_.publish(wheel_state_msg);
    }
    
private:  
    ros::NodeHandle n_;   
    ros::Publisher pub_;  
    ros::Subscriber sub_; 
    
};//End of class SubscribeAndPublish  
    
int main(int argc, char **argv)  
{  
    //Initiate ROS  
    ros::init(argc, argv, "excavator_jointstate_publisher");  
    //Create an object of class SubscribeAndPublish that will take care of everything  
    SubscribeAndPublish SAPObject;  
    ros::Rate loop_rate(50);
    ros::Duration delta(0.5);
    while(ros::ok())
    {
        if(ros::Time::now() - SAPObject.arm_state_msg.header.stamp > delta)
        {
            SAPObject.pub_arm_state();
        }
        SAPObject.pub_wheel_state();
        ros::spinOnce();  
        loop_rate.sleep();
    }
    // ros::spin();
    
    return 0;  
}  

