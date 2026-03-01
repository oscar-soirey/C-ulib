cmake_minimum_required(VERSION 3.10)

project(c_lib LANGUAGES C VERSION 1.0)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_COMPILER gcc)

add_executable(vector
vector_eg.c
)

add_executable(memory
memory_eg.c
)

add_executable(optional
optional_eg.c
)