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
        DemoClass(const ros::NodeHandle &nh);

        /**
         * Ctor.
         */
        virtual ~DemoClass();

        /**
         * Callback methods for subscribed topics.
         */
        void pointCB(const geometry_msgs::Point::ConstPtr& msg);

        void pointStampedCB(const geometry_msgs::PointStamped::ConstPtr& msg);

        void twistCB(const geometry_msgs::Twist::ConstPtr& msg);

    private:
        /*
         * Instantiation of ROS node handle
         */
        ros::NodeHandle nh_;

        /*
         * Instantiation of common_msg publishers
         */
        ros::Subscriber point_msg_sub_;
        ros::Subscriber pointstamped_msg_sub_;
        ros::Subscriber pose2d_msg_sub_;
        ros::Subscriber posestamped_msg_sub_;
        ros::Subscriber twist_msg_sub_;
        ros::Subscriber transform_msg_sub_;

        ros::Subscriber actionlib_msg_sub_;
        ros::Subscriber odometry_msg_sub_;
        ros::Subscriber laserScan_msg_sub_;
        ros::Subscriber joint_traj_point_msg_sub_;
};
#endif /** DEMO_CLASS_EXAMPLE_H_ **/