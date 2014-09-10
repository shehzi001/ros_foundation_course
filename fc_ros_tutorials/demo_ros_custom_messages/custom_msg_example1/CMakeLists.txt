cmake_minimum_required(VERSION 2.8.3)
project(custom_msg_example1)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  rospy
  std_msgs
  geometry_msgs
)


add_message_files(
  FILES
    NodeInfo.msg
    NodeData.msg
    NodesInfo.msg
 )


generate_messages(
  DEPENDENCIES
    std_msgs
    geometry_msgs
)


catkin_package(
  CATKIN_DEPENDS 
    message_runtime 
    roscpp 
    rospy 
    std_msgs
    geometry_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(custom_msg_cpp_simple_node 
  ros/src/custom_msg_cpp_simple_node.cpp)

target_link_libraries(custom_msg_cpp_simple_node
  ${catkin_LIBRARIES}
)
