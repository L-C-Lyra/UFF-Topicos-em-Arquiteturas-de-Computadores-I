cmake_minimum_required(VERSION 3.28.3)
project(MPI C)

set(CMAKE_C_STANDARD 11)

find_package(MPI REQUIRED)

add_executable(MPI
        trapezio.c)

target_include_directories(MPI PUBLIC ${MPI_C_INCLUDE_DIRS})

target_link_libraries(MPI PUBLIC ${MPI_C_LIBRARIES} m)
