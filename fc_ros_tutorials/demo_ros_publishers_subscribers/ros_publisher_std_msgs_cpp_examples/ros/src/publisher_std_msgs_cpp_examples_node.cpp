/**
 * publisher_std_msgs_cpp_examples_node.cpp
 *
 * Created on: September 09, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros/ros.h>
#include <ros_publisher_std_msgs_cpp_examples/demo_class_example.h>


int main(int argc, char *argv[])
{
    /**
     * Initilization of node
     **/
    ros::init(argc, argv, "publisher_std_msgs_cpp_examples_node");

    /**
     * Initilization of private node handle
     **/
    ros::NodeHandle nh("~");
    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("publisher_std_msgs_cpp_examples_node is now running");

    ros::Rate loop_rate(10);

    DemoClass demo_class(nh);

    /**
     * Keep loop untill the user node is killed.
     **/
     ROS_INFO("Press Cntrl+c to kill the node.");
    while(ros::ok()) {
        demo_class.prepareAndPublishMsgs();
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}