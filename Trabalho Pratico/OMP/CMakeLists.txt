cmake_minimum_required(VERSION 3.28.3)
project(OMP C)

set(CMAKE_C_STANDARD 11)

find_package(OpenMP REQUIRED)

add_executable(OMP
        trapezio.c)

target_link_libraries(OMP PUBLIC OpenMP::OpenMP_C m)
