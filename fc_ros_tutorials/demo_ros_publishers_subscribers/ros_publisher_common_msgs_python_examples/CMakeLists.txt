cmake_minimum_required(VERSION 2.8.3)
project(ros_publisher_common_msgs_python_examples)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  actionlib_msgs
  nav_msgs
  sensor_msgs
  trajectory_msgs 
  rospy
)

catkin_python_setup()

catkin_package(
  CATKIN_DEPENDS 
    geometry_msgs
    actionlib_msgs
    nav_msgs
    sensor_msgs
    trajectory_msgs
    rospy
)
