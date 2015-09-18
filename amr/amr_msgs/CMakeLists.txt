
cmake_minimum_required(VERSION 2.8.3)
project(amr_msgs)

# Load catkin and all dependencies required for this package
find_package(catkin REQUIRED 
  COMPONENTS
    genmsg
    actionlib
    actionlib_msgs
    sensor_msgs
    geometry_msgs
    nav_msgs
)

include_directories(include ${Boost_INCLUDE_DIR} ${catkin_INCLUDE_DIRS})

#include(${actionlib_msgs_PACKAGE_PATH}/cmake/actionbuild.cmake)
#genaction()

add_message_files(
  FILES
  Cone.msg
  Obstacle.msg
  PathExecutionFailure.msg
  Ranges.msg
  WheelSpeeds.msg
)

add_action_files(
  DIRECTORY
    action 
  FILES 
    ExecutePath.action 
    MoveTo.action
)

## Generate added messages and services with any dependencies listed here
generate_messages(
    DEPENDENCIES geometry_msgs std_msgs sensor_msgs nav_msgs actionlib_msgs
)

catkin_package(
    DEPENDS actionlib actionlib_msgs sensor_msgs geometry_msgs nav_msgs
    CATKIN_DEPENDS
    INCLUDE_DIRS
    LIBRARIES
)