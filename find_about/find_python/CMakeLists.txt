#-----------------------------------------------------------------------------------------------------------------------
#find 一个 python解析器
#这个找的是一个python2 why?
#[[
find_package(PythonInterp REQUIRED)
#执行外部命令
execute_process(
        COMMAND ${PYTHON_EXECUTABLE} "-c" "print('hello,python')"
        RESULT_VARIABLE _status
        OUTPUT_VARIABLE _out_info
        ERROR_QUIET
        OUTPUT_STRIP_TRAILING_WHITESPACE
)
message(STATUS "about res:${_status}")
message(STATUS "about output:${_out_info}")
]]#
#-----------------------------------------------------------------------------------------------------------------------
#添加python的头文件Python.h
#添加python运行时库libpython
#[[
find_package(PythonLibs
        ${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR} #这种版本可能找不到，所以换下一种方式
        EXACT
        REQUIRED)
]]#
#[[
find_package(PythonLibs
        #${PYTHON_VERSION_STRING}#这种版本也可能找不到，应该是FoundPythonLibs.cmake的问题
        #所以直接使用PythonInterp试一下
        #EXACT
        REQUIRED
        )
]]#


find_package (Python COMPONENTS Interpreter Development)
#使用官方的find_package后发现不能找到Development，应该是缺少头文件与库
#执行 $ sudo apt install python-dev  python3-dev 解决
#获取头文件目录

#include_directories(${Python_INCLUDE_DIRS})

message(STATUS "python include dir:${Python_INCLUDE_DIRS}")
add_executable(use_python use_python_test.h.cpp)

target_include_directories(use_python
        PRIVATE
        ${Python_INCLUDE_DIRS}
        )
TARGET_LINK_LIBRARIES(use_python
        PRIVATE
        ${Python_LIBRARIES}
        )












