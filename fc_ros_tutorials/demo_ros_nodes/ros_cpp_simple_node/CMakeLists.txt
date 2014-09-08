cmake_minimum_required(VERSION 2.8.3)
project(ros_cpp_simple_node)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package()

add_executable(ros_cpp_simple_node ros/src/ros_cpp_simple_node.cpp)

target_link_libraries(ros_cpp_simple_node
   ${catkin_LIBRARIES}
)
