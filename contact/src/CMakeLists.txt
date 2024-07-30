# 获取源文件来生成列表
aux_source_directory(./ SRC_LIST)

# 链接列表生成可执行文件
add_executable (${PROJECT_NAME} ../main.c ${SRC_LIST})
