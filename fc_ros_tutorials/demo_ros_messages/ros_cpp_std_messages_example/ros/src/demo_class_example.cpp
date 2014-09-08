/**
 * demo_class_example1.cpp
 *
 * Created on: September 08, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros_cpp_std_messages_example/demo_class_example.h>

DemoClass::DemoClass()
{
    initParameters(0, 0.0);
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


void DemoClass::prepareMessage()
{
    status_message_.data = false;
    sum_message_.data = total_sum_;
    count_message_.data = number_count_;
    event_message_.data = "hello";
}