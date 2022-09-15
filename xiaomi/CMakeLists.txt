cmake_minimum_required(VERSION 3.10.0)
project(xiaomi)

set(-std=c++11)
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

add_executable(test1 src/test1.cpp)
add_executable(test2 src/test2.cpp)