/**
 * demo_class_example2.h
 *
 * Created on: September 08, 2014
 * Author: Shehzad Ahmed
 **/
#ifndef DEMO_CLASS_EXAMPLE2_H_
#define DEMO_CLASS_EXAMPLE2_H_
#include <ros/ros.h>

class DemoClass
{
    public:
        /**
         * Ctor.
         */
        DemoClass()
        {
            initParameters(0, 0.0);
        }

        /**
         * Ctor.
         */
        ~DemoClass()
        {
        }

        
        /**
         * Method to initilize class variables, node parameters etc
         */
        void initParameters(int number_count, double total_sum)
        {
            ROS_INFO("Initlizing class variables.");
            number_count_ = number_count;
            total_sum_ = total_sum;
        }

    private:
        int number_count_;
        double total_sum_;
};
#endif /** DEMO_CLASS_EXAMPLE2_H_ **/