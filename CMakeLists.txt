cmake_minimum_required(VERSION 3.0)
project(complex)
include_directories(inc)
file(GLOB SOURCE "src/*.cpp" "inc/*.h")
add_executable(${PROJECT_NAME} ${SOURCE})


set(CMAKE_CXX_FLAGS "-Wall -pedantic")
add_definitions(${CMAKE_CXX_FLAGS})
