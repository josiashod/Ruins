cmake_minimum_required(VERSION 3.26)
project(PROJET)

set(CMAKE_CXX_STANDARD 17)

add_executable(PROJET
        doctest.h
        testmain.cpp
        point.h
        point.cpp
        testpoint.cpp)
