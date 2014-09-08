cmake_minimum_required(VERSION 2.8.3)
project(amr_ui)

# Load catkin and all dependencies required for this package
find_package(catkin REQUIRED
  COMPONENTS
    rospy
    actionlib
    tf
    sensor_msgs
    std_msgs
    geometry_msgs
    amr_msgs
    amr_srvs
)

include_directories(include
  ${Boost_INCLUDE_DIR}
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
    DEPENDS
    CATKIN_DEPENDS rospy actionlib tf sensor_msgs std_msgs geometry_msgs amr_msgs amr_srvs python-pyside
    INCLUDE_DIRS
    LIBRARIES
)