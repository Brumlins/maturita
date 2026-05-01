cmake_minimum_required(VERSION 3.30.5)
project(datum)

set(CMAKE_CXX_STANDARD 20)

add_executable(datum main.cpp
        datum.cpp
        datum.h)
