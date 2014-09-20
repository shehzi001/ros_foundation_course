/**
 * action_client_node.cpp
 *
 * Created on: September 10, 2014
 * Author: Shehzad Ahmed
 **/
#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <ros_action_server_client/RobotMotionAction.h>
#include <ros_action_server_client/RobotMotionGoal.h>

typedef actionlib::SimpleActionClient<ros_action_server_client::RobotMotionAction> Client;

int main(int argc, char *argv[])
{
    /**
     * Initilization of node
     **/
    ros::init(argc, argv, "action_client_node");

    /**
     * Initilization of node handle
     **/
    ros::NodeHandle nh;
    
    /**
     * Printing Information message on the console.
     **/
    ROS_INFO("action_client_node is now running");

    Client client("motion_planner", true);

    client.waitForServer();


    ros_action_server_client::RobotMotionGoal goal;

    /**
    filling a goal
    **/

    // Fill in goal here
    client.sendGoal(goal);

    client.waitForResult(ros::Duration(5.0));

    if (client.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
        ROS_INFO_STREAM("Action is successful");
    } 
    ROS_INFO_STREAM("Get current state" << client.getState().toString().c_str());
    /**
     * Running a thread to keep spinning untill the user kills the node.
     **/
    ros::spin();

    return 0;
}