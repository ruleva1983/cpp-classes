cmake_minimum_required(VERSION 3.1)
project(lapack_test)
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(lapack_test main.cpp)

target_link_libraries(lapack_test blas lapack)
