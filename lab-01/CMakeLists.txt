cmake_minimum_required(VERSION 3.26)
project(lab_01)

set(CMAKE_CXX_STANDARD 23)

add_executable(lab_01 main.cpp
        Headers/functions.h
        Sources/functions.cpp)
include_directories(Headers)