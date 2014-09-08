/**
 * std_messages_example_node.cpp
 *
 * Created on: September 08, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros/ros.h>
#include "ros_cpp_std_messages_example/demo_class_example.h"


int main(int argc, char *argv[])
{
    /**
     * Initilization of node
     **/
    ros::init(argc, argv, "std_messages_example_node");

    /**
     * Initilization of private node handle
     **/
    ros::NodeHandle nh("~");
    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("std_messages_example_node is now running");

    DemoClass demo_class;

    demo_class.initParameters(10, 10.0);

    /**
     * Running a thread to keep spinning untill the user kills the node.
     **/
    ROS_INFO("Press Cntrl+c to kill the node.");
    ros::spin();

    return 0;
}