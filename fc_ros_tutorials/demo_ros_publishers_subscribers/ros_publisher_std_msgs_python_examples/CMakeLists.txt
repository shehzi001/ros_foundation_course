cmake_minimum_required(VERSION 2.8.3)
project(ros_publisher_std_msgs_python_examples)

find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
)

catkin_python_setup()


catkin_package(
  CATKIN_DEPENDS
    rospy
    std_msgs
)
