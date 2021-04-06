cmake_minimum_required(VERSION 3.5)
project (TestLibrary)
 
#SHARED LIBRARY
#set ( PROJECT_LINK_LIBS libtestStudent.so )
#link_directories( /home/ruggero/repositories/cpp-classes/meetings/7-cmake/d-compiling_libraries/build )

 
#STATIC LIBRARY:
set ( PROJECT_LINK_LIBS libtestStudent_static.a )
link_directories( /home/ruggero/repositories/cpp-classes/meetings/7-cmake/d-compiling_libraries/build )
 
include_directories( /home/ruggero/repositories/cpp-classes/meetings/7-cmake/d-compiling_libraries/include )
 
add_executable(libtest main.cpp)
target_link_libraries(libtest ${PROJECT_LINK_LIBS} )
