cmake_minimum_required(VERSION 3.10)
project(ad_interfaces)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenCV
find_package(OpenCV REQUIRED)

# Include directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Create a header-only library
add_library(perception INTERFACE)
target_include_directories(perception INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Link OpenCV libraries
target_link_libraries(perception INTERFACE ${OpenCV_LIBS})

# Install the header files
install(DIRECTORY include/perception DESTINATION include)

# Install the library
install(TARGETS perception
    EXPORT ad_interfaces-targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

# Install the CMake configuration files
install(EXPORT ad_interfaces-targets
    FILE ad_interfaces-config.cmake
    NAMESPACE ad_interfaces::
    DESTINATION lib/cmake/ad_interfaces
)

# Export the package for use from the build tree
export(EXPORT ad_interfaces-targets
    FILE "${CMAKE_CURRENT_BINARY_DIR}/ad_interfaces-config.cmake"
    NAMESPACE ad_interfaces::
)