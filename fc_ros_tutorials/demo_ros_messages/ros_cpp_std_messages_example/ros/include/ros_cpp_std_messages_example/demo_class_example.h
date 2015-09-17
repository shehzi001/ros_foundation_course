/**
 * demo_class_example1.h
 *
 * Created on: September 08, 2014
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
        DemoClass();

        /**
         * Ctor.
         */
        virtual ~DemoClass();

        
        /**
         * Method to initilize class variables, node parameters etc
         */
        void initParameters(int number_count, double total_sum);

        /**
         * prepare example ros messages.
         */
        void prepareMessage();

    private:
        int number_count_;
        double total_sum_;
        std_msgs::Bool status_message_;
        std_msgs::Float32 sum_message_;
        std_msgs::Int32 count_message_;
        std_msgs::String event_message_;
};
#endif /** DEMO_CLASS_EXAMPLE_H_ **/