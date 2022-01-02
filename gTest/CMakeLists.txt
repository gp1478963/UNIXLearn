find_package(GTest REQUIRED)

find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)

#add_executable(gTestAbout )