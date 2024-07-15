cmake_minimum_required(VERSION 3.28)

get_filename_component(PROJECT_NAME ${CMAKE_SOURCE_DIR} NAME)
project(${PROJECT_NAME} C)

set(CMAKE_C_STANDARD 99)

aux_source_directory (src SRC_LIST)

include_directories (inc)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
 
add_executable (${PROJECT_NAME} ${SRC_LIST})