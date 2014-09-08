cmake_minimum_required(VERSION 2.8.3)
project(amr_srvs)

# Load catkin and all dependencies required for this package
find_package(catkin REQUIRED
  COMPONENTS
    geometry_msgs
    amr_msgs
)

include_directories(include ${Boost_INCLUDE_DIR} ${catkin_INCLUDE_DIRS})

add_service_files(
  FILES
  GetNearestOccupiedPointInCone.srv
  GetPoseLikelihood.srv
  IsLineSegmentFree.srv
  PlanPath.srv
  GetNearestOccupiedPointOnBeam.srv
  GetRangers.srv
  IsPointFree.srv
  SwitchRanger.srv
)

## Generate added messages and services with any dependencies listed here
generate_messages(
    DEPENDENCIES geometry_msgs std_msgs amr_msgs
)

catkin_package(
    DEPENDS
    CATKIN_DEPENDS geometry_msgs amr_msgs
    INCLUDE_DIRS
    LIBRARIES
)