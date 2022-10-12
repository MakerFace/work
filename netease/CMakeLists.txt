cmake_minimum_required(VERSION 3.5)
project(NETEASE)

set(-std=c++11)

add_executable(test1 src/test1.cpp)
add_executable(test2 src/test2.cpp)
add_executable(test3 src/test3.cpp)
add_executable(test4 src/test4.cpp)

target_link_libraries(test2 -fsanitize=address)