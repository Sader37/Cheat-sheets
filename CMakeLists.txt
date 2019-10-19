cmake_minimum_required(VERSION 3.14)
project(main)

set(CMAKE_CXX_STANDARD 17)
set(MYSQL_CONN_DIR "C:/Program Files/MySQL/MySQL Connector C++ 8.0")

find_package(Boost 1.71.0 REQUIRED)

include_directories(${MYSQL_CONN_DIR}/include)

link_directories(${MYSQL_CONN_DIR}/lib64/vs14)

set(SOURCE_FILES main.cpp)
add_executable(main ${SOURCE_FILES})

target_link_libraries(main mysqlcppconn8 ${Boost})
