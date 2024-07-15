# 设置cmake最低版本
cmake_minimum_required(VERSION 3.28)
# 设置项目名
get_filename_component(PROJECT_NAME ${CMAKE_SOURCE_DIR} NAME)
project(${PROJECT_NAME} C)
# C标准
set(CMAKE_C_STANDARD 99)
# 头文件路径
include_directories(${PROJECT_SOURCE_DIR}/inc)
# 可执行文件生成路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 库文件生成路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# 链接源文件生成程序
add_subdirectory(./src)
# 链接库生成程序
# add_subdirectory(./lib)


# 生成库

# # 获取源文件来生成列表
# aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)
# # 根据列表生成共享库和静态库
# add_library(PROJECT_SHARED SHARED ${SRC_LIST})
# add_library(PROJECT_STATIC STATIC ${SRC_LIST})
# # 设置生成的库文件名
# set_target_properties(PROJECT_SHARED PROPERTIES 
# OUTPUT_NAME ${PROJECT_NAME})
# set_target_properties(PROJECT_STATIC PROPERTIES 
# OUTPUT_NAME ${PROJECT_NAME})