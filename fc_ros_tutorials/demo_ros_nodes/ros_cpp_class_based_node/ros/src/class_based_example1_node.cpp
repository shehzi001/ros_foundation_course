/**
 * class_based_example1_node.cpp
 *
 * Created on: September 08, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/PointStamped.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Twist.h>
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

        void publish_msg()
        {
            
            geometry_msgs::Twist twist;

            twist.linear.x = 0.0;
            twist.linear.y = 0.5;
            twist.angular.z = 0.5;
        }

    private:
        int number_count_;
        double total_sum_;
        std_msgs::String event_out_msg_;
        std_msgs::Bool node_status_;
        geometry_msgs::Point point_msg_;
        geometry_msgs::PointStamped point_stamped_msg_;
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
