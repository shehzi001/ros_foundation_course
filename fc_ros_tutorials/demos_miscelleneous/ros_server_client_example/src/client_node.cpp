/**
 * simple_client_cpp_example_node.cpp
 *
 * Created on: September 10, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros/ros.h>
#include <ros_server_client_example/NodeInfo.h>
#include <ros_server_client_example/NodeInfoRequest.h>
#include <ros_server_client_example/NodeInfoResponse.h>


int main(int argc, char *argv[])
{
    /**
     * Initilization of node
     **/
    ros::init(argc, argv, "ros_client_node");

    /**
     * Initilization of node handle
     **/
    ros::NodeHandle nh;
    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("ros_client_node is now running");

    ros::ServiceClient client = nh.serviceClient<ros_server_client_example::NodeInfo>("node_info_query");

    if(client.exists()) {
        ROS_INFO("server found.....");
        ros_server_client_example::NodeInfo node_info_query;
        ros_server_client_example::NodeInfoRequest request;
        request.node_name.data = "ros_client_node";

        node_info_query.request = request;

        if(client.call(node_info_query)) {
            ROS_INFO_STREAM("Response recieved :" << node_info_query.response.node_id.data);
        } else {
            ROS_INFO("Response failed.....");
        }

    } else {
        ROS_INFO("server is not running.....");
    }

    return 0;
}