/**
 * class_based_example2_node.cpp
 *
 * Created on: September 08, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros/ros.h>
#include <ros_cpp_class_based_node/demo_class_example3.h>


int main(int argc, char *argv[])
{
    /**
     * Initilization of node
     **/
    ros::init(argc, argv, "class_based_example3_node");

    /**
     * Initilization of private node handle
     **/
    ros::NodeHandle nh("~");
    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("class_based_example3_node is now running");

    DemoClass demo_class;

    demo_class.initParameters(10, 10.0);

    /**
     * Running a thread to keep spinning untill the user kills the node.
     **/
    ROS_INFO("Press Cntrl+c to kill the node.");
    ros::spin();

    return 0;
}