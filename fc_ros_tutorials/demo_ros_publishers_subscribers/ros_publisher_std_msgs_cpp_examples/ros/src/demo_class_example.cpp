/**
 * demo_class_example.cpp
 *
 * Created on: September 09, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros_publisher_std_msgs_cpp_examples/demo_class_example.h>

DemoClass::DemoClass(const ros::NodeHandle &nh):
        nh_(nh)
{
    initParameters(0, 0.0);

    bool_msg_pub_ = nh_.advertise<std_msgs::Bool>("node_status", 100);

    float_msg_pub_ = nh_.advertise<std_msgs::Float32>("total_sum", 100);

    int_msg_pub_ = nh_.advertise<std_msgs::Int32>("number_count", 100);

    string_msg_pub_ = nh_.advertise<std_msgs::String>("node_event", 100);
}


DemoClass::~DemoClass()
{
}


void DemoClass::initParameters(int number_count, double total_sum)
{
    ROS_INFO("Initlizing class variables.");
    number_count_ = number_count;
    total_sum_ = total_sum;
}


void DemoClass::prepareAndPublishMsgs()
{
    status_message_.data = false;
    sum_message_.data = total_sum_;
    count_message_.data = number_count_;
    event_message_.data = "hello";


    bool_msg_pub_.publish(status_message_);
    float_msg_pub_.publish(sum_message_);
    int_msg_pub_.publish(count_message_);
    string_msg_pub_.publish(event_message_);
}