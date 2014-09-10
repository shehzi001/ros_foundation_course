/**
 * simple_client_cpp_example_node.cpp
 *
 * Created on: September 10, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros/ros.h>
#include <ros_services_examples/NodeInfoQuery.h>
#include <ros_services_examples/NodeInfoQueryRequest.h>
#include <ros_services_examples/NodeInfoQueryResponse.h>

class DemoClass
{
    public:
        DemoClass(const ros::NodeHandle &nh):
            nh_(nh)
        {
            client_ = nh_.serviceClient<ros_services_examples::NodeInfoQuery>("node_info_query");
        }

        ~DemoClass()
        {
        }

        void call_service()
        {
            if(client_.exists()) {
                ROS_INFO("server is running.....");
                ros_services_examples::NodeInfoQuery node_info_query;
                ros_services_examples::NodeInfoQueryRequest request;
                request.node_name.data = "simple_client_cpp_example_node";

                node_info_query.request = request;

                if(client_.call(node_info_query)) {
                    ROS_INFO_STREAM("Response recieved :" << node_info_query.response.node_id.data);
                } else {
                    ROS_INFO("Response failed.....");
                }
            } else {
                    ROS_INFO("server is not running.....");
            }
        }

    private:
        ros::ServiceClient client_;
        ros::NodeHandle nh_;
};

int main(int argc, char *argv[])
{
    /**
     * Initilization of node
     **/
    ros::init(argc, argv, "simple_client_cpp_example_node");

    /**
     * Initilization of node handle
     **/
    ros::NodeHandle nh;
    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("simple_client_cpp_example_node is now running");

    DemoClass demo_class(nh);

    demo_class.call_service();

    /**
     * Running a thread to keep spinning untill the user kills the node.
     **/

    return 0;
}