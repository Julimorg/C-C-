cmake_minimum_required(VERSION 3.27)
project(Cpp_and_C__)

set(CMAKE_CXX_STANDARD 14)

include_directories(Basic)

add_executable(Cpp_and_C__
        Basic/HelloWorld.cpp
        Basic/HelloWorld.h)
