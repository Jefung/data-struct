# 将当前目录下所有.cpp文件包含进来.
# 注意: 当使用clion时, file()必须在每次增加/删除文件时reload project
file(GLOB_RECURSE source_files "*.cpp")

## 加上boost编译
#find_package(Boost 1.58.0 REQUIRED COMPONENTS system filesystem)
#include_directories(${Boost_INCLUDE_DIRS})
#target_link_libraries(${CMAKE_PROJECT_NAME}_run ${Boost_LIBRARIES})

foreach (file_path ${source_files})
    string(REPLACE ".cpp" "" new_name ${file_path})
    get_filename_component(filename ${new_name} NAME)
    # 生成可执行文件
    add_executable(${filename} ${file_path})
endforeach ()

