cmake_minimum_required(VERSION 2.8.3)
project(ros_cpp_class_based_node)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
)

catkin_package(
  CATKIN_DEPENDS 
    roscpp 
    std_msgs 
    geometry_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ros/include
)

#=====================================
add_executable(class_based_example1_node 
  ros/src/class_based_example1_node.cpp)

target_link_libraries(class_based_example1_node
  ${catkin_LIBRARIES}
)

#=====================================
add_executable(class_based_example2_node 
  ros/src/class_based_example2_node.cpp
)
target_link_libraries(class_based_example2_node
  ${catkin_LIBRARIES}
)

#=====================================
add_executable(class_based_example3_node 
  ros/src/class_based_example3_node.cpp
  ros/src/demo_class_example3.cpp
)
target_link_libraries(class_based_example3_node
  ${catkin_LIBRARIES}
)
