cmake_minimum_required(VERSION 3.23)
project(matrix C)

set(CMAKE_C_STANDARD 23)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_executable(matrix main.c)
