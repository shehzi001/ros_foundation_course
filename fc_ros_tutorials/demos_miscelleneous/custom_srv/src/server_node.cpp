/**
 * simple_server_cpp_example_node.cpp
 *
 * Created on: September 10, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros/ros.h>
#include <custom_srv/NodeInfo.h>
#include <custom_srv/NodeInfoRequest.h>
#include <custom_srv/NodeInfoResponse.h>

bool  cbNodeId(custom_srv::NodeInfoRequest &req, custom_srv::NodeInfoResponse &res)
{
    ROS_INFO_STREAM("Request message:" << req.node_name.data);
    res.node_id.data = 1.0;
    return false;
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

    ros::ServiceServer server = nh.advertiseService("node_id_allocator", cbNodeId);

    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("ros_server_node is now running");

    /**
     * Running a thread to keep spinning untill the user kills the node.
     **/
    ros::spin();

    return 0;
}

