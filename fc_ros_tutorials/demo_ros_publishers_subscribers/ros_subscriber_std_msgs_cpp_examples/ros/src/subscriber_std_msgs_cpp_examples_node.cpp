/**
 * publisher_std_msgs_cpp_examples_node.cpp
 *
 * Created on: September 09, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros/ros.h>
#include <ros_subscriber_std_msgs_cpp_examples/demo_class_example.h>


int main(int argc, char *argv[])
{
    /**
     * Initilization of node
     **/
    ros::init(argc, argv, "subscriber_std_msgs_cpp_examples_node");

    /**
     * Initilization of private node handle
     **/
    ros::NodeHandle nh("~");
    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("subscriber_std_msgs_cpp_examples_node is now running");

    ros::Rate loop_rate(10);

    DemoClass demo_class(nh);

    /**
     * Keep loop untill the user node is killed.
     **/
    ROS_INFO("Press Cntrl+c to kill the node.");
    ros::spin();
    return 0;
}