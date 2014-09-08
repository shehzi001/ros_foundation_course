/**
 * demo_class_example3.cpp
 *
 * Created on: September 08, 2014
 * Author: Shehzad Ahmed
 **/

#include "ros_cpp_class_based_node/demo_class_example3.h"

DemoClass::DemoClass()
{
    initParameters(0, 0.0);
}


/**
 * Ctor.
 */
DemoClass::~DemoClass()
{
}


/**
 * Method to initilize class variables, node parameters etc
 */
void DemoClass::initParameters(int number_count, double total_sum)
{
    ROS_INFO("Initlizing class variables.");
    number_count_ = number_count;
    total_sum_ = total_sum;
}