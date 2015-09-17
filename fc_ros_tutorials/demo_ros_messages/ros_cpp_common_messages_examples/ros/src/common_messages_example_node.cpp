/**
 * common_messages_example_node.cpp
 *
 * Created on: September 08, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros/ros.h>
#include "ros_cpp_common_messages_examples/demo_class_example.h"


int main(int argc, char *argv[])
{
    /**
     * Initilization of node
     **/
    ros::init(argc, argv, "common_messages_example_node");

    /**
     * Initilization of private node handle
     **/
    ros::NodeHandle nh("~");
    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("common_messages_example_node is now running");

    DemoClass demo_class;

    /**
     * Running a thread to keep spinning untill the user kills the node.
     **/
    ROS_INFO("Press Cntrl+c to kill the node.");
    ros::spin();

    return 0;
}