project ( cpp_classes-cmake )

cmake_minimum_required ( VERSION 3.5 )

 
find_package(OpenMP)

message (${OPENMP_FOUND})
message (${OpenMP_CXX_FLAGS})


#find_package(PostgreSQL)

# use cmake options when calling cmake
# -DENABLE_POSTGRESQL=1
# -DPOSTGRESQL_INCLUDE_DIR=/usr/include/postgresql/
# -DPOSTGRESQL_LIBRARY=/usr/lib/x86_64-linux-gnu/libpq.so.5
# -DPostgreSQL_TYPE_INCLUDE_DIR=/usr/include/postgresql/

message (${POSTGRESQL_INCLUDE_DIR})


