cmake_minimum_required(VERSION 3.0.0)
project(path_plan VERSION 0.1.0 LANGUAGES C CXX)

add_executable(path_plan 
    src/main.cpp
    src/Geometry.h
    src/Plane.h
    src/Crater.h
)