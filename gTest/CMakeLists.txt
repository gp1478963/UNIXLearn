cmake_minimum_required(VERSION 3.16)
project(gTestAbout)


find_package(GTest REQUIRED)

find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)

#add_executable(gTestAbout )