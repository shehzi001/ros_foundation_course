cmake_minimum_required(VERSION 2.8.3)
project(ros_simple_client_python)

find_package(catkin REQUIRED COMPONENTS
  ros_services_examples
  rospy
)

catkin_package(
  CATKIN_DEPENDS 
    ros_services_examples 
    rospy
)