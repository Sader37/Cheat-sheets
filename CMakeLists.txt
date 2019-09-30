cmake_minimum_required(VERSION 3.14)
project(main)

SET(CMAKE_CXX_STANDARD 17)
SET(SOURCE_FILES main.cpp modules/examples2.cpp)
SET(MYSQL_CONN_DIR "C:/Program Files/MySQL/MySQL Connector C++ 8.0")

include_directories(${MYSQL_CONN_DIR}/include)
include_directories(${MYSQL_CONN_DIR}/include/mysqlx)

add_executable(main ${SOURCE_FILES})

link_directories(${MYSQL_CONN_DIR}/lib64)
link_directories(${MYSQL_CONN_DIR}/lib64/vs14)

SET(LIBRARIES ${MYSQL_CONN_DIR}/lib64/vs14/mysqlcppconn8.lib)

target_link_libraries(main ${LIBRARIES})

