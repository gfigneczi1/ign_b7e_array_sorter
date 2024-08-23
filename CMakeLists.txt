cmake_minimum_required(VERSION 3.8)
project(array_sorter)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

set(ament_dependencies
  rclcpp
  std_msgs
  geometry_msgs
)

add_executable(array_sorter src/array_sorter.cpp)
add_executable(array_publisher src/array_publisher.cpp)
# first node to execute sorting and publish new topic
ament_target_dependencies(array_sorter ${ament_dependencies} )

# second node to publish the topic
ament_target_dependencies(array_publisher ${ament_dependencies} )

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})

install(TARGETS
array_sorter
array_publisher
DESTINATION lib/${PROJECT_NAME})

ament_package()