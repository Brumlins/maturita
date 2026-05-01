cmake_minimum_required(VERSION 3.30.5)
project(zlomek)

set(CMAKE_CXX_STANDARD 17)

add_executable(zlomek main.cpp
        fraction.cpp
        fraction.h)
