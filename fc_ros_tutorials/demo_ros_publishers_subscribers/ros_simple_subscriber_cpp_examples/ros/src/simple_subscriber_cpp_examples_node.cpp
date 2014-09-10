/**
 * publisher_std_msgs_cpp_examples_node.cpp
 *
 * Created on: September 09, 2014
 * Author: Shehzad Ahmed
 **/
#include <ros/ros.h>
#include <std_msgs/String.h>



void eventInCB(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO_STREAM("eventInCB message:" << msg->data);
}


int main(int argc, char *argv[])
{
    /**
     * Initilization of node
     **/
    ros::init(argc, argv, "simple_subscriber_cpp_examples_node");

    /**
     * Initilization of private node handle
     **/
    ros::NodeHandle nh("~");
    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("simple_subscriber_cpp_examples_node is now running");

    ros::Subscriber event_in_sub = nh.subscribe("event_in", 100, eventInCB);

    ros::Rate loop_rate(10);

    /**
     * Keep loop untill the user node is killed.
     **/
    ROS_INFO("Press Cntrl+c to kill the node.");
    ros::spin();
    return 0;
}