cmake_minimum_required ( VERSION 3.5 )

project ( cpp_classes-cmake )

#add_executable (Hello main.cpp)

# Default compiler is gcc (for C) and g++ (for C++). To change compiler, e.g.
# to clang there are three options. 

# 1) Use env variables:  CC=/path/to/compiler/binary/forc 
#                        CXX=/path/to/compiler/binary/forc++


# 2) Pass the variables as command line argument plus where to look for it

# cmake .. -D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++ /usr/bin/

# 3) Set the variables in the CMakeLists.txt file (many tell to avoid it...no reason why)

# set(CMAKE_C_COMPILER "/usr/bin/clang")
# set(CMAKE_CXX_COMPILER "/usr/bin/clang")

#You can also use an option


option(USE_CLANG "build application with clang" ON)

if (USE_CLANG)
  set(CMAKE_C_COMPILER "/usr/bin/clang")
  set(CMAKE_CXX_COMPILER "/usr/bin/clang")
endif ()
add_executable (Hello main.cpp)

