cmake_minimum_required(VERSION 3.8)
project(untitled6)

set(CMAKE_C_STANDARD 90)

set(SOURCE_FILES main.c)
add_executable(untitled6 ${SOURCE_FILES})
target_link_libraries(untitled6 m)