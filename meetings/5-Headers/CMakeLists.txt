cmake_minimum_required(VERSION 3.0)
project(matrix VERSION 0.1)

set(SOURCES main.cpp 
    src/Matrix.cpp)
add_executable(matrix ${SOURCES})