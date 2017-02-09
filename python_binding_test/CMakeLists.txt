cmake_minimum_required(VERSION 2.8.3)
project(python_binding_test)

find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
)

find_package(Boost REQUIRED COMPONENTS python)
find_package(PythonLibs REQUIRED)

catkin_python_setup()

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES hello_world greet world
  CATKIN_DEPENDS rospy roscpp
)


include_directories(
  include
  ${PYTHON_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
  ${boost_INCLUDE_DIRS}
)

add_library(greet src/greet.cpp)
add_library(world src/world.cpp)
add_library(hello_world src/hello_world.cpp)
target_link_libraries(hello_world ${PYTHON_LIBRARIES} ${Boost_LIBRARIES} ${catkin_LIBRARIES} greet world)

set_target_properties(hello_world PROPERTIES OUTPUT_NAME hello PREFIX "" SUFFIX ".so")
set_target_properties(hello_world PROPERTIES COMPILE_FLAGS "-g -Wno-missing-field-initializers")
set_target_properties(hello_world PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_PYTHON_DESTINATION}
  LIBRARY_OUTPUT_DIRECTORY ${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_PYTHON_DESTINATION}
)
