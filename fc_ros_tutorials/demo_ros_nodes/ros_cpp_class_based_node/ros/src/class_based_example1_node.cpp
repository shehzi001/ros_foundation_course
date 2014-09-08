/**
 * class_based_example1_node.cpp
 *
 * Created on: September 08, 2014
 * Author: Shehzad Ahmed
 **/

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


int main(int argc, char *argv[])
{
    /**
     * Initilization of node
     **/
    ros::init(argc, argv, "class_based_example1_node");

    /**
     * Initilization of private node handle
     **/
    ros::NodeHandle nh("~");
    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("class_based_example1_node is now running");

    DemoClass demo_class;

    demo_class.initParameters(10, 10.0);

    /**
     * Running a thread to keep spinning untill the user kills the node.
     **/
    ros::spin();

    return 0;
}