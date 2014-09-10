/**
 * simple_server_cpp_example_node.cpp
 *
 * Created on: September 10, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros/ros.h>
#include <ros_services_examples/NodeInfoQuery.h>
#include <ros_services_examples/NodeInfoQueryRequest.h>
#include <ros_services_examples/NodeInfoQueryResponse.h>


bool serviceCB(ros_services_examples::NodeInfoQueryRequest &req, 
               ros_services_examples::NodeInfoQueryResponse &resp)
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
    ros::init(argc, argv, "simple_server_cpp_example_node");

    /**
     * Initilization of node handle
     **/
    ros::NodeHandle nh;
    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("simple_server_cpp_example_node is now running");

    ros::ServiceServer service = nh.advertiseService("node_info_query", serviceCB);

    /**
     * Running a thread to keep spinning untill the user kills the node.
     **/
    ros::spin();

    return 0;
}