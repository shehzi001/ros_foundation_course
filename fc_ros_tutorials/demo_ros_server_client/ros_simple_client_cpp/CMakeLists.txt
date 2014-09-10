cmake_minimum_required(VERSION 2.8.3)
project(ros_simple_client_cpp)

find_package(catkin REQUIRED COMPONENTS
  ros_services_examples
  roscpp
)

catkin_package(
  CATKIN_DEPENDS 
    ros_services_examples 
    roscpp
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)


add_executable(simple_client_cpp_example_node 
  ros/src/simple_client_cpp_example_node.cpp)

target_link_libraries(simple_client_cpp_example_node
  ${catkin_LIBRARIES}
)

add_executable(client_cpp_class_based_example_node 
  ros/src/client_cpp_class_based_example_node.cpp)

target_link_libraries(client_cpp_class_based_example_node
  ${catkin_LIBRARIES}
)