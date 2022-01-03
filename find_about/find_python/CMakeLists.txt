#-----------------------------------------------------------------------------------------------------------------------
#find 一个 python解析器
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






















#-----------------------------------------------------------------------------------------------------------------------