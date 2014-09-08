/**
 * demo_class_example3.h
 *
 * Created on: September 08, 2014
 * Author: Shehzad Ahmed
 **/
#ifndef DEMO_CLASS_EXAMPLE3_H_
#define DEMO_CLASS_EXAMPLE3_H_
#include <ros/ros.h>

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

    private:
        int number_count_;
        double total_sum_;
};
#endif /** DEMO_CLASS_EXAMPLE3_H_ **/