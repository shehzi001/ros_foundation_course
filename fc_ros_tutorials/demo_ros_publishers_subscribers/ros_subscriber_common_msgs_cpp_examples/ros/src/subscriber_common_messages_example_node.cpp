/**
 * subscriber_common_messages_example_node.cpp
 *
 * Created on: September 08, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros/ros.h>
#include "ros_subscriber_common_msgs_cpp_examples/demo_class_example.h"


int main(int argc, char *argv[])
{
    /**
     * Initilization of node
     **/
    ros::init(argc, argv, "subscriber_common_messages_example_node");

    /**
     * Initilization of private node handle
     **/
    ros::NodeHandle nh("~");
    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("subscriber_common_messages_example_node is now running");

    DemoClass demo_class(nh);

    /**
     * Keep loop untill the user node is killed.
     **/
    ROS_INFO("Press Cntrl+c to kill the node.");
    ros::spin();
    
    return 0;
}