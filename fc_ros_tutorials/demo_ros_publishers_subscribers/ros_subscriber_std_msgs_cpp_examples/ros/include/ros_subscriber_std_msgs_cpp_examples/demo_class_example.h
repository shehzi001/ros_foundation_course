/**
 * demo_class_example.h
 *
 * Created on: September 09, 2014
 * Author: Shehzad Ahmed
 **/
#ifndef DEMO_CLASS_EXAMPLE_H_
#define DEMO_CLASS_EXAMPLE_H_
#include <ros/ros.h>

#include <std_msgs/Bool.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>

class DemoClass
{
    public:
        /**
         * Ctor.
         */
        DemoClass(const ros::NodeHandle &nh);

        /**
         * Ctor.
         */
        virtual ~DemoClass();

        /**
         * Callback methods for topics
         */
        void nodeStatusCB(const std_msgs::Bool::ConstPtr& msg);

        void totalSumCB(const std_msgs::Float32::ConstPtr& msg);

    private:
        ros::NodeHandle nh_;
        
        /*
         * std_msg publishers
         */
        ros::Subscriber bool_msg_sub_;
        ros::Subscriber float_msg_sub_;
        ros::Subscriber int_msg_sub_;
        ros::Subscriber string_msg_sub_;
};
#endif /** DEMO_CLASS_EXAMPLE_H_ **/