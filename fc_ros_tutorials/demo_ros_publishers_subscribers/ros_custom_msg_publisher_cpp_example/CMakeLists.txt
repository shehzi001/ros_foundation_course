cmake_minimum_required(VERSION 2.8.3)
project(ros_custom_msg_publisher_cpp_example)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  custom_msg_example1
)

catkin_package(
  CATKIN_DEPENDS
    roscpp
    custom_msg_example1
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(custom_msg_publisher_cpp_example_node
  ros/src/custom_msg_publisher_cpp_example_node.cpp
)

target_link_libraries(custom_msg_publisher_cpp_example_node
  ${catkin_LIBRARIES}
)