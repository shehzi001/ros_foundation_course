/**
 * simple_time_example_node.cpp
 *
 * Created on: September 10, 2014
 * Author: Shehzad Ahmed
 **/
#include <ros/ros.h>

void rosTimeExamples()
{
    ros::Time now = ros::Time::now();

    ROS_INFO_STREAM("Time Now:" << now);

    ros::Duration duration(5.0);

    ROS_INFO_STREAM("duration:" << duration);

    //ROS duration sleep()
    ros::Duration(0.5).sleep();

    ros::Rate r(10); // 10 hz
    while (ros::ok())
    {
      r.sleep();
    }
}

int main(int argc, char *argv[])
{
    /*
     * Initilization of node
     */
    ros::init(argc, argv, "simple_time_example_node");

    /*
     * Starting node.
     */
    ros::NodeHandle nh("~");

    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("simple_time_example_node is now running");

    rosTimeExamples();
    
    //ros::spin();

    return 0;
}