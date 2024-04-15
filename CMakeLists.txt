cmake_minimum_required(VERSION 3.10)
project(the_DepthDelve_Project)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)



set(CMAKE_OBJECT_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../obj)




find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)


file(GLOB SOURCE_FILES src/*.cpp)
file(GLOB HEADER_FILES src/*.h)


add_executable(DepthDelve ${SOURCE_FILES} ${HEADER_FILES})


target_link_libraries(DepthDelve sfml-graphics sfml-window sfml-system)


target_include_directories(DepthDelve PRIVATE src)
