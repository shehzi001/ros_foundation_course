/**
 * demo_class_example.h
 *
 * Created on: September 08, 2014
 * Author: Shehzad Ahmed
 **/
#ifndef DEMO_CLASS_EXAMPLE_H_
#define DEMO_CLASS_EXAMPLE_H_
#include <ros/ros.h>

#include <geometry_msgs/Point.h>
#include <geometry_msgs/PointStamped.h>
#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/PoseWithCovariance.h>
#include <geometry_msgs/TwistWithCovariance.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Transform.h>
#include <actionlib_msgs/GoalID.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/Range.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>

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
         * prepare example ros messages.
         */
        void prepareGeometryMsg();

        void prepareActionlibMsg();
        void prepareOdometryMsg();
        void prepareLaserScanMsg();
        void prepareRangeMsg();
        void prepareJointTrajectoyPointMsg();

    private:
        geometry_msgs::Point point_message_;
        geometry_msgs::PointStamped pointstamped_message_;
        geometry_msgs::Pose2D pose2d_message_;
        geometry_msgs::PoseStamped posestamped_message_;
        geometry_msgs::Twist twist_message_;
        geometry_msgs::Transform transform_message_;

        actionlib_msgs::GoalID goal_id_message_;
        nav_msgs::Odometry odomety_message_;
        sensor_msgs::LaserScan laser_scan_message_;
        sensor_msgs::Range range_message_;
        trajectory_msgs::JointTrajectoryPoint joint_trajectory_point_message_;
};
#endif /** DEMO_CLASS_EXAMPLE_H_ **/