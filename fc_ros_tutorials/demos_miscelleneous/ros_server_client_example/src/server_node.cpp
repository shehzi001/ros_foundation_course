/**
 * simple_server_cpp_example_node.cpp
 *
 * Created on: September 10, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros/ros.h>
#include <ros_server_client_example/NodeInfo.h>
#include <ros_server_client_example/NodeInfoRequest.h>
#include <ros_server_client_example/NodeInfoResponse.h>


bool serviceCB(ros_server_client_example::NodeInfoRequest &req, 
               ros_server_client_example::NodeInfoResponse &resp)
{
    ROS_INFO_STREAM("Request recieved :" << req.node_name.data);
    resp.node_id.data = 1.0;
    return true;
}

int main(int argc, char *argv[])
{
    /**
     * Initilization of node
     **/
    ros::init(argc, argv, "ros_server_node");

    /**
     * Initilization of node handle
     **/
    ros::NodeHandle nh;
    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("ros_server_node is now running");

    ros::ServiceServer service = nh.advertiseService("node_info_query", serviceCB);

    /**
     * Running a thread to keep spinning untill the user kills the node.
     **/
    ros::spin();

    return 0;
}