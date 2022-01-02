cmake_minimum_required(VERSION 3.16)
project(UNIXLearn)


find_package(GTest REQUIRED)

find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)



add_executable(UNIXLearn main.cpp
                    unix_interface_test.h
                    unix_interface_test.cpp
                    template_polices_about.h
                    template_polices_about.cpp)

add_subdirectory(gTest)