cmake_minimum_required(VERSION 2.8.3)
project(ros_python_class_based_nodes)

find_package(catkin REQUIRED COMPONENTS
  rospy
)

catkin_python_setup()

catkin_package(
  CATKIN_DEPENDS
    rospy
)

install(PROGRAMS
  ros/scripts/class_based_example1_node
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(PROGRAMS
  ros/scripts/class_based_example2_node
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)