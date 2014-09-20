/**
 * simple_publisher_cpp_examples_node.cpp
 *
 * Created on: September 09, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros/ros.h>

#include <ros_custom_msg_example/NodeInfo.h>


int main(int argc, char *argv[])
{
    /**
     * Initilization of node
     **/
    ros::init(argc, argv, "custom_msg_publisher_node");

    /**
     * Initilization of private node handle
     **/
    ros::NodeHandle nh("~");
    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("custom_msg_publisher_node is now running");

    /*
     * Initilizing topic and then filling the message for topic.
     */

    ros::Publisher node_info_pub = nh.advertise<ros_custom_msg_example::NodeInfo>("/node_info", 100);

    //std_msgs::String event_message;

    //event_message.data = "hello";

    /*
     * Declaring and initilizing loop frequency.
     */

    ros_custom_msg_example::NodeInfo node_info_msg;
    ros::Rate loop_rate(5);
    std_msgs::String node_name_;
    std_msgs::Int32 node_id_;

    node_name_.data = "custom_msg_publisher";
    node_id_.data = 1;

    node_info_msg.node_name = node_name_;
    node_info_msg.node_id = node_id_;

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