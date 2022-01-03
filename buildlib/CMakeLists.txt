include(CMakeDependentOption)
#-------------------------------------------------------------------------------
# 函数： add_library() 与 add_executable() 使用
#add_library 的第二个参数:STATIC SHARED
#比较简单的构筑，直接生成静态/动态库
#[[
add_library(message
        STATIC
        #SHARED
        printf_message.h
        printf_message.cpp
        )

add_executable(TestAboutMessage message_test.cpp)
target_link_libraries(TestAboutMessage message)
]]#

#-------------------------------------------------------------------------------
# 函数： add_library()
#add_library 的第二个参数:OBJECT
#OBJECT 使用：主要整合源文件,感觉跟list(APPEND secures .cpp .h)差不多;
#set_target_properties()：设置目标属性，好像失败了不知道为什么
#[[
add_library(message-objs
        OBJECT
        printf_message.h
        printf_message.cpp
        )

#使用OBJECT生成库
add_library(message-shared
        SHARED
        $<TARGET_OBJECTS:message-objs>
        )


add_library(message-static
        STATIC
        $<TARGET_OBJECTS:message-objs>
        )

#为统一库的名称

#[[
set_target_properties(message-shared
        PROPERTIES
        OUTPUT_NAME "message")
]]#

#[[
set_target_properties(message-static
        PROPERTIES
        OUTPUT_NAME "message")
]]#
#link
#add_executable(TestAboutMessage message_test.cpp)
#target_link_libraries(TestAboutMessage message) 无法工作
#target_link_libraries(TestAboutMessage message-static)


#-------------------------------------------------------------------------------
#控制语句练习

#[[
set(USER_LIBRARES YES)

set(BUILD_SHARED_LIBS YES)
list(APPEND _sources printf_message.h printf_message.cpp)

if(USER_LIBRARES)
    add_library(message ${_sources})
    add_executable(TestAboutMessage message_test.cpp)
    target_link_libraries(TestAboutMessage message)
else(USER_LIBRARES)
    add_executable(TestAboutMessage message_test.cpp ${_sources})
endif(USER_LIBRARES)# end if USER_LIBRARES
]]#

#-------------------------------------------------------------------------------
#硬编码方式过于死板，使用option解决这个问题
option(USER_LIBRARES "Compiler sources into a library" NO) #设置变量默认值:USER_LIBRARES=NO
#在cmake的时候，可以通过-D 选项来传递信息
#只有USER_LIBRARES=YES，BUILD_SHARED_LIB变量才有意义，cmake_


cmake_dependent_option(
        MAKE_STATIC_LIBRARY "Compiler sources into a static library" OFF
        "USER_LIBRARES" ON
    )
cmake_dependent_option(
        BUILD_SHARED_LIBS "Compiler sources into a SHARED library" ON
        "USER_LIBRARES" ON
)

#set(BUILD_SHARED_LIBS YES)
list(APPEND _sources printf_message.h printf_message.cpp)

if(USER_LIBRARES)
    add_library(message ${_sources})
    add_executable(TestAboutMessage message_test.cpp)
    target_link_libraries(TestAboutMessage message)
else(USER_LIBRARES)
    add_executable(TestAboutMessage message_test.cpp ${_sources})
endif(USER_LIBRARES)# end if USER_LIBRARES

#-------------------------------------------------------------------------------

#系统平台相关

message(STATUS "this is a ${CMAKE_SYSTEM_NAME} os" )





















