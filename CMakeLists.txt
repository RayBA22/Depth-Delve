cmake_minimum_required(VERSION 3.10) 

project(the_DepthDelve_Project)  

file(GLOB SOURCE_FILES ./src/*.cpp)

file(GLOB HEADER_FILES ./src/*.h)

add_executable(DepthDelve ${SOURCE_FILES} ${HEADER_FILES})