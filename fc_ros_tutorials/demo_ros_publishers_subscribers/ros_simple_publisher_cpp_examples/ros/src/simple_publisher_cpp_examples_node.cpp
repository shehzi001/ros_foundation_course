/**
 * simple_publisher_cpp_examples_node.cpp
 *
 * Created on: September 09, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros/ros.h>

#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>


int main(int argc, char *argv[])
{
    /**
     * Initilization of node
     **/
    ros::init(argc, argv, "simple_publisher_cpp_examples_node");

    /**
     * Initilization of private node handle
     **/
    ros::NodeHandle nh("~");
    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("simple_publisher_cpp_exampless_node is now running");

    /*
     * Initilizing topic and then filling the message for topic.
     */

    ros::Publisher twist_msg_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 100);

    std_msgs::String event_message;

    event_message.data = "hello";

    geometry_msgs::Twist twist_msg;

    twist_msg.angular.z = 0.5;

    /*
     * Declaring and initilizing loop frequency.
     */
    ros::Rate loop_rate(5);

    /**
     * Keep looping and publish the topic at loop rate
     * untill the node is not killed.
     **/
     ROS_INFO("Press Cntrl+c to kill the node.");
    while(ros::ok()) {
        twist_msg_pub.publish(twist_msg);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}