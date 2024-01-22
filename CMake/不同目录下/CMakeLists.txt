# 设置cmake最低版本
cmake_minimum_required(VERSION 3.20)
    
# 设置编译器
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
    
# 设置项目名
project(cmake_test)

#设置文件搜索路径
#CMAKE_CURRENT_SOURCE_DIR代表CMakeLists的当前路径
#表示把CMakeLists的当前路径的文件打包到SCR中
file(GLOB SCR1 ${CMAKE_CURRENT_SOURCE_DIR}/mainCode/*.c)

#指定头文件
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


# 添加可执行目标
add_executable(out ${SCR1})
