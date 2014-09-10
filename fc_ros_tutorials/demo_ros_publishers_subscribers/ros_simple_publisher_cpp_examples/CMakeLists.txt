cmake_minimum_required(VERSION 2.8.3)
project(ros_simple_publisher_cpp_examples)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS
    roscpp
    std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(simple_publisher_cpp_examples
  ros/src/simple_publisher_cpp_examples_node.cpp
)

target_link_libraries(simple_publisher_cpp_examples
  ${catkin_LIBRARIES}
)