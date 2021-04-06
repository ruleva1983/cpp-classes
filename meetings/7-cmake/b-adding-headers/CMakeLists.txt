project ( cpp_classes-cmake )

cmake_minimum_required ( VERSION 3.5 )

# It will include a path where to search for header files. The path is calculated
# starting from the location of the CMakeLists.txt file.

include_directories( include )
include_directories( include/utils )

add_executable (Hello main.cpp)
