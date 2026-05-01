cmake_minimum_required(VERSION 3.30)
project(rodnecislo)

set(CMAKE_CXX_STANDARD 17)

add_executable(rodnecislo main.cpp
        rodne.cpp
        rodne.h)
