/**
 * custom_msg_publisher_cpp_example_node.cpp
 *
 * Created on: September 09, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros/ros.h>

#include <custom_msg_example1/NodeInfo.h>


int main(int argc, char *argv[])
{
    /**
     * Initilization of node
     **/
    ros::init(argc, argv, "custom_msg_publisher_cpp_example_node");

    /**
     * Initilization of private node handle
     **/
    ros::NodeHandle nh("~");
    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("custom_msg_publisher_cpp_example_node is now running");

    /*
     * Initilizing topic and then filling the message for topic.
     */

    ros::Publisher node_info_pub = nh.advertise<custom_msg_example1::NodeInfo>("node_info", 100);

    custom_msg_example1::NodeInfo node_info_msg;

    node_info_msg.node_name.data = "custom_msg_publisher";
    node_info_msg.node_status.data = true;
    node_info_msg.node_id.data = 0;
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
        node_info_pub.publish(node_info_msg);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}