cmake_minimum_required(VERSION 2.8.3)
project(ros_cpp_std_messages_example)

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

add_executable(std_messages_example
  ros/src/std_messages_example_node.cpp
  ros/src/demo_class_example.cpp
)

target_link_libraries(std_messages_example
  ${catkin_LIBRARIES}
)
