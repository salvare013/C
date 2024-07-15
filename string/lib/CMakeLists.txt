# 获取库文件来生成列表
file(GLOB LIB_LIST "./*.so")

# 链接列表生成可执行文件
add_executable (${PROJECT_NAME} ../main.c)
target_link_libraries(${PROJECT_NAME} ${LIB_LIST})