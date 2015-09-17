cmake_minimum_required(VERSION 2.8.3)
project(ros_publisher_std_msgs_cpp_examples)

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
  ros/include
)

add_executable(publisher_std_msgs_cpp_examples_node 
  ros/src/publisher_std_msgs_cpp_examples_node.cpp
  ros/src/demo_class_example.cpp
)

target_link_libraries(publisher_std_msgs_cpp_examples_node
  ${catkin_LIBRARIES}
)