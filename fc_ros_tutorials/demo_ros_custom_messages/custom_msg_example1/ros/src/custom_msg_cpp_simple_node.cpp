/**
 * custom_msg_simple_node.cpp
 *
 * Created on: September 08, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros/ros.h>
#include <custom_msg_example1/NodeInfo.h>
 #include <custom_msg_example1/NodesInfo.h>



int main(int argc, char *argv[])
{
    /**
     * Initilization of ROS
     **/
    ros::init(argc, argv, "custom_msg_simple_node");

    /**
     * Initilization of node by using node handle
     **/
    ros::NodeHandle nh("~");
    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("custom_msg_cpp_simple_node is now running");

    /*
     * Filling a simple custom message
     */
    custom_msg_example1::NodeInfo node_info_msg;

    node_info_msg.node_name.data = "custom_msg_cpp_simple_node";
    node_info_msg.node_status.data = false;
    node_info_msg.node_id.data = 1;

    /*
     * Filling a an array custom message
     */
    int number_of_nodes = 5;
    custom_msg_example1::NodesInfo nodes_info_msg;
    nodes_info_msg.node_name.resize(number_of_nodes);
    nodes_info_msg.node_status.resize(number_of_nodes);
    nodes_info_msg.node_id.resize(number_of_nodes);

    for(int i=0;i < number_of_nodes; i++) {
        nodes_info_msg.node_name.at(i).data = "custom_msg_cpp_simple_node ";
        nodes_info_msg.node_status.at(i).data = false;
        nodes_info_msg.node_id.at(i).data = i;
    }

    /**
     * Running a thread to keep spinning untill the user kills the node.
     **/
    ros::spin();

    return 0;
}