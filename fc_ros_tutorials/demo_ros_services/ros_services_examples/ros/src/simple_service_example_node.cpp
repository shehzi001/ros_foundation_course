/**
 * simple_service_example_node.cpp
 *
 * Created on: September 10, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros/ros.h>
#include <ros_services_examples/NodeInfoQueryRequest.h>
#include <ros_services_examples/NodeInfoQueryResponse.h>

int main(int argc, char *argv[])
{
    /**
     * Initilization of node
     **/
    ros::init(argc, argv, "simple_service_example_node");

    /**
     * Initilization of node handle
     **/
    ros::NodeHandle nh("~");
    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("simple_service_example_node is now running");

    /*
     * Filling service request message
     */
    ros_services_examples::NodeInfoQueryRequest node_info_query_request;

    node_info_query_request.node_name.data = "simple_service_example_node";

    /*
     * Filling service response message
     */
    ros_services_examples::NodeInfoQueryResponse node_info_query_reponse;

    node_info_query_reponse.node_id.data = 1.0;

    /**
     * Running a thread to keep spinning untill the user kills the node.
     **/
    ros::spin();

    return 0;
}