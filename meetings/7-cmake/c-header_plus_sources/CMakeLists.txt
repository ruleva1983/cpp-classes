cmake_minimum_required ( VERSION 3.5 )

project ( cpp_classes-cmake )

include_directories( include )

#add_executable (Hello ./src/Student.cpp main.cpp)

set(sources ./src/Student.cpp)



add_executable (Hello ${sources} main.cpp)
