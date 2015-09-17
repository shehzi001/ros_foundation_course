cmake_minimum_required(VERSION 2.8.3)
project(ros_server_client_example)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  message_generation
)

add_service_files(
  FILES
  NodeInfo.srv
 )


generate_messages(
  DEPENDENCIES
    std_msgs
)

catkin_package(
  CATKIN_DEPENDS 
    message_runtime 
    roscpp 
    rospy 
    std_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)


add_executable(ros_server_node 
  src/server_node.cpp)

target_link_libraries(ros_server_node
  ${catkin_LIBRARIES}
)

add_executable(ros_client_node 
  src/client_node.cpp)

target_link_libraries(ros_client_node
  ${catkin_LIBRARIES}
)
