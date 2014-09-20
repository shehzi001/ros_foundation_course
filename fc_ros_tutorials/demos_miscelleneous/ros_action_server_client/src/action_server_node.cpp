/**
 * action_server_node.cpp
 *
 * Created on: September 10, 2014
 * Author: Shehzad Ahmed
 **/

#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <ros_action_server_client/RobotMotionAction.h>
#include <ros_action_server_client/RobotMotionGoal.h>
 typedef actionlib::SimpleActionServer<ros_action_server_client::RobotMotionAction> Server;

void execute(const ros_action_server_client::RobotMotionGoalConstPtr &goal, Server* as)
{
     ROS_INFO("Goal recieved");

     as->setSucceeded();
}

int main(int argc, char *argv[])
{
    /**
     * Initilization of node
     **/
    ros::init(argc, argv, "action_server_node");

    /**
     * Initilization of node handle
     **/
    ros::NodeHandle nh;
    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("action_server_node is now running");

    Server server(nh, "motion_planner", boost::bind(&execute, _1, &server), false);
    
    server.start();
    /**
     * Running a thread to keep spinning untill the user kills the node.
     **/
    ros::spin();

    return 0;
}