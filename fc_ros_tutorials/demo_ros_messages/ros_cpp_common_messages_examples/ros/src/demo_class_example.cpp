/**
 * demo_class_example.cpp
 *
 * Created on: September 08, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros_cpp_common_messages_examples/demo_class_example.h>

DemoClass::DemoClass()
{
    prepareGeometryMsg();
}


DemoClass::~DemoClass()
{
}

void DemoClass::prepareGeometryMsg()
{
    /*
     * Filling point message
     */
    point_message_.x = 1.0;
    point_message_.y = 1.0;
    point_message_.z = 1.0;

    /*
     * Filling twist message.
     * Specify Robot velocity in the x-direction 
     * with 1.0 rad/sec.
     */
    twist_message_.linear.x = 1.0;
    twist_message_.linear.y = 0.0;
    twist_message_.linear.z = 0.0;

    twist_message_.angular.x = 0.0;
    twist_message_.angular.y = 0.0;
    twist_message_.angular.z = 0.0;

    /*
     * Filling point stamped
     */
    pointstamped_message_.header.stamp = ros::Time::now();
    pointstamped_message_.header.frame_id = "frame_dummy";

    pointstamped_message_.point.x = 1.0;
    pointstamped_message_.point.y = 1.0;
    pointstamped_message_.point.z = 1.0;

    /*
     * Filling Transform message
     * Do it your self for practice
     */

    /*
     * Filling pose2d message
     * Do it your self for practice
     */

    /*
     * Filling posestamped message
     * Do it your self for practice
     */
}


void DemoClass::prepareActionlibMsg()
{
    /*
     * Filling goal_id message
     */
    goal_id_message_.stamp = ros::Time::now();
    goal_id_message_.id = "ACTIVE";
}


void DemoClass::prepareOdometryMsg()
{
    /*
     * nav_msgs example.
     * Filling odom message.
     * Step 1: Prepare pose and twist messages separatly.
     * Step 2: Fill the data in actual message odomety_message_.
     */
    geometry_msgs::PoseWithCovariance pose;
    geometry_msgs::TwistWithCovariance twist;

    /*
    odomety_message_.header.stamp = ros::Time::now();;
    odomety_message_.header.frame_id = "odom_frame";
    odomety_message_.child_frame_id = "base_frame";
    odomety_message_.pose = pose;
    odomety_message_.twist = twist;
    odomety_message_.covariance = 0.5;
    */
}


void DemoClass::prepareLaserScanMsg()
{
     /*
     * sensor_msgs example
     * Filling laser scan message
     * Step 1: Prepare data to be filled
     * Step 2: Fill actual message with the prepared data.
     */

    //Step 1: 
        unsigned int num_readings = 100;
        double laser_frequency = 40;
        double ranges[num_readings];
        double intensities[num_readings];
        int count = 0;

        //generate some fake data for laser scan
        for (unsigned int i = 0; i < num_readings; ++i) {
            ranges[i] = count;
            intensities[i] = 4 + count;
        }

    //Step 2
        laser_scan_message_.header.stamp = ros::Time::now();
        laser_scan_message_.header.frame_id = "laser_frame";
        laser_scan_message_.angle_min = -1.57;
        laser_scan_message_.angle_max = 1.57;
        laser_scan_message_.angle_increment = 3.14 / num_readings;
        laser_scan_message_.time_increment = (1 / laser_frequency) / (num_readings);
        laser_scan_message_.range_min = 0.0;
        laser_scan_message_.range_max = 4.0;

        laser_scan_message_.ranges.resize(num_readings);
        laser_scan_message_.intensities.resize(num_readings);
        for (unsigned int i = 0; i < num_readings; ++i) {
          laser_scan_message_.ranges[i] = ranges[i];
          laser_scan_message_.intensities[i] = intensities[i];
        }
}


void DemoClass::prepareRangeMsg()
{
    /*
     * sensor_msgs example
     * Filling range messages
     * Do it your self for practice
     * Message to be filled is range_message_
     */
}

void DemoClass::prepareJointTrajectoyPointMsg()
{
    /*
     * trajectory_msgs example
     * Filling JointTrajectoyPoint message
     * Do it your self for practice
     * Step 1: Prepare data to be filled
     * Step 2: Fill actual message with the prepared data.
     * Message to be filled is joint_trajectory_point_message_.
     */
}