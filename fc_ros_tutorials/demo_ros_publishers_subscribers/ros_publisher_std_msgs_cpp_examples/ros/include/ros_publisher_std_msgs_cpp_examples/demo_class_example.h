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
         * Method to initilize class variables, node parameters etc
         */
        void initParameters(int number_count, double total_sum);

        /**
         * prepare and publish example ros messages.
         */
        void prepareAndPublishMsgs();

    private:
        ros::NodeHandle nh_;

        int number_count_;
        double total_sum_;
        std_msgs::Bool status_message_;
        std_msgs::Float32 sum_message_;
        std_msgs::Int32 count_message_;
        std_msgs::String event_message_;

        /*
         * std_msg publishers
         */
        ros::Publisher bool_msg_pub_;
        ros::Publisher float_msg_pub_;
        ros::Publisher int_msg_pub_;
        ros::Publisher string_msg_pub_;
};
#endif /** DEMO_CLASS_EXAMPLE_H_ **/