cmake_minimum_required(VERSION 2.8.3)
project(ros_time_examples)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  message_generation
)

catkin_package(
  CATKIN_DEPENDS 
    roscpp 
    rospy 
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(simple_time_example_cpp_node
  ros/src/simple_time_example_node.cpp)

target_link_libraries(simple_time_example_cpp_node
   ${catkin_LIBRARIES}
)
