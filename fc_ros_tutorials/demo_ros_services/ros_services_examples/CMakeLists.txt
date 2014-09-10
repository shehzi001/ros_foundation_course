cmake_minimum_required(VERSION 2.8.3)
project(ros_services_examples)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  message_generation
)

add_service_files(
  FILES
    NodeInfoQuery.srv
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
  ${catkin_INCLUDE_DIRS}
)

add_executable(simple_service_example_node 
  ros/src/simple_service_example_node.cpp)

target_link_libraries(simple_service_example_node
   ${catkin_LIBRARIES}
)
