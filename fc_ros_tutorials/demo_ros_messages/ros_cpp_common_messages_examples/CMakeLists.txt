cmake_minimum_required(VERSION 2.8.3)
project(ros_cpp_common_messages_examples)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  actionlib_msgs
  nav_msgs
  sensor_msgs
  trajectory_msgs 
  roscpp
)

catkin_package(
  CATKIN_DEPENDS 
    geometry_msgs
    actionlib_msgs
    nav_msgs
    sensor_msgs
    trajectory_msgs
    roscpp
)


include_directories(
  ${catkin_INCLUDE_DIRS}
  ros/include
)

add_executable(common_messages_examples 
  ros/src/common_messages_example_node.cpp
  ros/src/demo_class_example.cpp
)

target_link_libraries(common_messages_examples
   ${catkin_LIBRARIES}
)