/**
 * demo_class_example.cpp
 *
 * Created on: September 09, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros_subscriber_std_msgs_cpp_examples/demo_class_example.h>

DemoClass::DemoClass(const ros::NodeHandle &nh):
        nh_(nh)
{
    bool_msg_sub_ = nh_.subscribe("node_status", 100, &DemoClass::nodeStatusCB, this);

    float_msg_sub_ = nh_.subscribe("total_sum", 100, &DemoClass::totalSumCB, this);

    /*
     * Please, Do it yourself. 
     * Write code to subscribe to Int32 type topic "number_count"
     */

    /*
     * Please, Do it yourself.  
     * Write code to subscribe to String type topic "node_event"
     */
}


DemoClass::~DemoClass()
{
}


void DemoClass::nodeStatusCB(const std_msgs::Bool::ConstPtr& msg)
{
    if (msg->data) {
        ROS_INFO_STREAM("nodeStatusCB message:" << "true");
    } else {
        ROS_INFO_STREAM("nodeStatusCB message:" << "false");
    }
}  

void DemoClass::totalSumCB(const std_msgs::Float32::ConstPtr& msg)
{
    ROS_INFO_STREAM("totalSumCB message:" << msg->data);
}

/*
 * Please, Do it yourself. 
 * Write callback method for Int32 type topic
 */


/*
 * Please, Do it yourself. 
 * Write callback method for String type topic
 */
