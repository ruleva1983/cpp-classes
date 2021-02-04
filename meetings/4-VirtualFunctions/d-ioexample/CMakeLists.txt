# CMakeLists.txt
# Date: 2020-04-09
# Author: Ruggero Vasile (ruleva1983@gmail.com)

project ( ioabstractreader )

find_package ( Boost )
include_directories ( SYSTEM ${Boost_INCLUDE_DIRS} )

add_executable ( IO main.cpp )
