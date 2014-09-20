/**
 * simple_client_cpp_example_node.cpp
 *
 * Created on: September 10, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros/ros.h>
#include <custom_srv/NodeInfo.h>
#include <custom_srv/NodeInfoRequest.h>
#include <custom_srv/NodeInfoResponse.h>


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

    //client creation
    ros::ServiceClient client = nh.serviceClient<custom_srv::NodeInfo>("node_id_allocator");
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("ros_client_node is now running");

    if(client.exists()) { //checking if service exits
        //prepare req message
        custom_srv::NodeInfoRequest req_msg;
        req_msg.node_name.data = "client_node";
        //prepare request
        custom_srv::NodeInfo service;
        service.request = req_msg;

        //call the service
        bool service_status = client.call(service); //blocking call

        if(service_status){
            //service response
            ROS_INFO_STREAM("Response message :" << service.response.node_id.data);
        }  else {
            ROS_INFO_STREAM("Service failure.");
        }  
    }

    return 0;
}
