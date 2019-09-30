cmake_minimum_required(VERSION 3.14)
project(main)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_VERBOSE_MAKEFILE ON) 
set(MYSQL_CONN_DIR "C:/Program Files/MySQL/MySQL Connector C++ 8.0")

#add_library(say-hello SHARED hello.hpp hello.cpp)

include_directories(${MYSQL_CONN_DIR}/include)
include_directories(${MYSQL_CONN_DIR}/include/mysqlx)

link_directories(${MYSQL_CONN_DIR}/lib64)
link_directories(${MYSQL_CONN_DIR}/lib64/vs14)

set(SOURCE_FILES main.cpp modules/examples2.cpp)
add_executable(main ${SOURCE_FILES})

#target_link_libraries(main say-hello)
target_link_libraries(main mysqlcppconn8-2-vs14.dll mysqlcppconn8.lib)

