find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

if(GTest_FOUND)
    message("GTest find")
endif()

include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
add_executable(FirstTest test_about.cpp )

target_link_libraries(FirstTest ${GTEST_BOTH_LIBRARIES})
target_link_libraries(FirstTest ${CMAKE_THREAD_LIBS_INIT})

add_test(Test FirstTest)
enable_testing()