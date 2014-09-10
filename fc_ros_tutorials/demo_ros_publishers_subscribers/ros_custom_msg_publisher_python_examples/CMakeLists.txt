cmake_minimum_required(VERSION 2.8.3)
project(ros_custom_msg_publisher_python_examples)

find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
  custom_msg_example1
)

catkin_package(
  CATKIN_DEPENDS
    rospy
    std_msgs
    custom_msg_example1
)
