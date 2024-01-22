# 设置cmake最低版本
cmake_minimum_required(VERSION 3.20)
    
# 设置编译器
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
    
# 设置项目名
project(cmake_test)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SCR)
    
# 添加可执行目标
add_executable(out ${SCR})
