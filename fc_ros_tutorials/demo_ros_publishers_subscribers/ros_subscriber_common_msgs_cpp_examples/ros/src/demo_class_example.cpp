/**
 * demo_class_example.cpp
 *
 * Created on: September 09, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros_subscriber_common_msgs_cpp_examples/demo_class_example.h>

DemoClass::DemoClass(const ros::NodeHandle &nh):
        nh_(nh)
{
    point_msg_sub_ = nh_.subscribe("point", 100, 
                    &DemoClass::pointCB, this);

    pointstamped_msg_sub_ = nh_.subscribe("stamped_point", 100, 
                    &DemoClass::pointStampedCB, this);

    twist_msg_sub_ = nh_.subscribe("twist", 100,
                    &DemoClass::twistCB, this);
    
    /*
     * Please, write the code to subscribe for 
     * the topics of following message types:
     * PoseStamped, Pose2D, Transform, GoalID, Odometry 
     * LaserScan, Range, JointTrajectoryPoint
     * 
     * and also write the required callback method. 
     * 
     * Topic names are:
     *  posestamped_msg_sub
     *  pose2d_msg_sub
     *  transform_msg_sub
     *  actionlib_msg_sub
     *  odometry_msg_sub
     *  laserScan_msg_sub
     *  joint_traj_point_msg_sub
     */
}


DemoClass::~DemoClass()
{
}


void DemoClass::pointCB(const geometry_msgs::Point::ConstPtr &msg)
{
    ROS_INFO_STREAM("pointCB message:(" << 
                    msg->x << "," <<
                    msg->y << "," << 
                    msg->z << ")"
                    );
}


void DemoClass::pointStampedCB(const geometry_msgs::PointStamped::ConstPtr &msg)
{
    geometry_msgs::PointStamped point_stamped_msg = *msg;
    ROS_INFO_STREAM("pointStampedCB message:(" <<
                    msg->point.x << "," <<
                    msg->point.y << "," <<
                    msg->point.z << ")"
                    );
}


void DemoClass::twistCB(const geometry_msgs::Twist::ConstPtr &msg)
{
    geometry_msgs::Twist twist = *msg;

    ROS_INFO_STREAM("twistCB message: " <<
                    "linear(" << 
                    twist.linear.x << "," <<
                    twist.linear.y << "," <<
                    twist.linear.z << ")" <<
                    "angular(" <<
                    twist.angular.x << "," <<
                    twist.angular.y << "," << 
                    twist.angular.z << ")"
                    );
}