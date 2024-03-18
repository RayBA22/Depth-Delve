cmake_minimum_required(VERSION 3.10)
project(the_DepthDelve_Project)

# Find SDL2 package
find_package(SDL2 REQUIRED)

# Set source files
file(GLOB SOURCE_FILES ./src/*.cpp)
file(GLOB HEADER_FILES ./src/*.h)

# Include SDL2 headers
include_directories(${SDL2_INCLUDE_DIRS})

# Create executable
add_executable(DepthDelve ${SOURCE_FILES} ${HEADER_FILES})

# Link SDL2 libraries
target_link_libraries(DepthDelve ${SDL2_LIBRARIES})
