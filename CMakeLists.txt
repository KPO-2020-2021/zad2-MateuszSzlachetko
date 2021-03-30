cmake_minimum_required(VERSION 3.1)
project(complex)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(tst)
add_subdirectory(lib/googletest)

include_directories(inc)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true inc/*.h src/*.cpp)
set(SOURCE ${SOURCES})


set(CMAKE_CXX_FLAGS "-Wall -pedantic")
add_definitions(${CMAKE_CXX_FLAGS})
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCE})
