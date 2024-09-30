# 设置cmake版本要求
cmake_minimum_required(VERSION 3.22...3.30 FATAL_ERROR)
# 设置项目名
get_filename_component(PROJECT_NAME ${CMAKE_SOURCE_DIR} NAME)
project(${PROJECT_NAME} C)
# C标准
set(CMAKE_C_STANDARD 11)
# 可执行文件生成路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)
# 库文件生成路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)
# 获取库文件来生成列表
# file(GLOB LIB_LIST "./*.dll")
# 获取源文件来生成列表
aux_source_directory(./ SRC_LIST)
# 链接列表生成可执行文件
add_executable (${PROJECT_NAME} ${SRC_LIST})

# 链接库文件列表
# target_link_libraries(${PROJECT_NAME} ${LIB_LIST})

# 生成动态库
# add_library(PRO_DLL_LIB SHARED ./1.c)
# set_target_properties(PRO_DLL_LIB PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
