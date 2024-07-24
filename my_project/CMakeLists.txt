cmake_minimum_required(VERSION 3.10)
project(my_project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)



# Find ad-interfaces package
set(ad_interfaces_DIR ~/include/lib/cmake/ad_interfaces)
find_package(ad_interfaces REQUIRED)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Add executable
add_executable(my_project src/main.cpp)

# Link ad-interfaces library
target_link_libraries(my_project ad_interfaces::perception ${OpenCV_LIBS})