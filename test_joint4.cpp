#include "ros/ros.h"
#include "std_msgs/Float64.h"

//for sin()
#include <math.h>

float X;
float Y = 0;

void joint4angleCallback(const std_msgs::Float64 msg)
{
        X = msg.data;
        if (X > Y)
        {
			ROS_INFO("X: %f", X);
        }else{
			ROS_INFO("The number should be larger than previous!!!");
		}
        Y = X;


//ROS_INFO("  ");

}

int main(int argc, char **argv){
ros::init(argc, argv, "testing");
X = 0;
ros::NodeHandle nh;

//task 2
//ros::Publisher pub3 = nh.advertise<std_msgs::Float64>("/robot/joint4_position_controller/command", 10);
ros::Publisher pub1 = nh.advertise<std_msgs::Float64>("/robot/joint1_position_controller/command", 10);
//ros::Publisher pub5 = nh.advertise<std_msgs::Float64>("/robot/joint5_position_controller/command", 10);
ros::Subscriber sub = nh.subscribe("des_joint4_angle", 10, joint4angleCallback);



// /robot/joint4_position_controller/command

// /joint4/command
ros::Rate loop_rate(1); // x per sec 

ros::Time startTime = ros::Time::now();

float i = 0.0;
float k;
float time = 0.0;
	//for step
        while (ros::ok()) {
			k = sin(i); 
			if (k > 0){
				k=1;
				
			}else{
				k = 0;
			}
				// time = ros::Time::now().toSec();
                  std_msgs::Float64 msg_to_send;
				// msg_to_send.data = sin(time);
					
                  msg_to_send.data = X;
                  pub1.publish(msg_to_send);
                  ROS_INFO("Moving joint 4");
                  ros::spinOnce();
                  loop_rate.sleep();
       }
       return 0;
}
