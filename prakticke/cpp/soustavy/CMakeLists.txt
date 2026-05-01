cmake_minimum_required(VERSION 3.30.5)
project(soustavy)

set(CMAKE_CXX_STANDARD 20)

add_executable(soustavy main.cpp
        soustava.cpp
        soustava.h)
