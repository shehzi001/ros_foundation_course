cmake_minimum_required(VERSION 2.8.3)
project(amr_stage)

find_package(Boost REQUIRED 
  COMPONENTS 
    thread
    filesystem
)

find_package(catkin REQUIRED
  COMPONENTS
    roscpp
    dynamic_reconfigure
    std_msgs
    nav_msgs
    tf
    geometry_msgs
    sensor_msgs
    robot_state_publisher
    amr_msgs
    amr_srvs
)

find_package(FLTK REQUIRED)

find_package(orocos_kdl REQUIRED)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
set(ROS_BUILD_TYPE RelWithDebInfo)

# add dynamic reconfigure API
generate_dynamic_reconfigure_options(
  cfg/Stage.cfg
)

# set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#...: compiler options :......................................................

add_definitions(-std=gnu++0x)
add_definitions(-Wall)
add_definitions(-Wno-error=unused-variable)
add_definitions(-Wno-error=unknown-pragmas)
add_definitions(-Wno-error=address)
add_definitions(-Wno-deprecated)

#...: dependencies :..........................................................

#...: stage
find_path(STAGE_INCLUDE_DIR stage.hh
  /opt/ros/hydro/include/Stage-4.1/
)
find_library(STAGE_LIBRARY stage
  /opt/ros/hydro/lib64
  /opt/ros/hydro/lib
  /opt/ros/hydro/lib/Stage-4.1/
  /opt/ros/hydro/lib64/Stage-4.1/
)

if(NOT STAGE_INCLUDE_DIR OR NOT STAGE_LIBRARY)
  message(SEND_ERROR "Could not find Stage-4.1 installation under /opt/ros/hydro.")
endif(NOT STAGE_INCLUDE_DIR OR NOT STAGE_LIBRARY)

include_directories(
  include
  cfg/cpp
  ${catkin_INCLUDE_DIRS}
  ${STAGE_INCLUDE_DIR}
  ${Boost_INCLUDE_DIR}
  ${orocos_kdl_INCLUDE_DIRS}
)

#...: target executables :....................................................

add_executable(stage
  nodes/stage.cpp
  src/ranger.cpp
  src/laser.cpp
  src/sonar.cpp
  src/base.cpp
)

add_dependencies(stage 
  ${PROJECT_NAME}_gencfg
  ${catkin_EXPORTED_TARGETS}
)

target_link_libraries(stage 
  ${STAGE_LIBRARY}
  ${FLTK_LIBRARIES}
  ${Boost_LIBRARIES}
  ${catkin_LIBRARIES}
  ${orocos_kdl_LIBRARIES}
)

catkin_package(
    DEPENDS orocos_kdl
    CATKIN_DEPENDS roscpp std_msgs nav_msgs tf geometry_msgs sensor_msgs robot_state_publisher dynamic_reconfigure amr_msgs amr_srvs
    INCLUDE_DIRS
    LIBRARIES
)
