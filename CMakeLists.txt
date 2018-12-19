cmake_minimum_required(VERSION 3.0)
project(Port)

set(CMAKE_CXX_STANDARD 11)

add_executable(Port src/main.cpp src/port.h src/vintage_port.h src/port.cpp src/vintage_port.cpp)
