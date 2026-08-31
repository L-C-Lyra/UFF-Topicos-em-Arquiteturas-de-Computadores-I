cmake_minimum_required(VERSION 3.28.3)
project(07___Exemplo_02 C)

set(CMAKE_C_STANDARD 11)

find_package(MPI REQUIRED)

add_executable(07___Exemplo_02 main.c)

target_include_directories(07___Exemplo_02 PUBLIC ${MPI_C_INCLUDE_DIRS})

target_link_libraries(07___Exemplo_02 PUBLIC ${MPI_C_LIBRARIES})
