cmake_minimum_required(VERSION 3.19)
project(tiny_thread_pool C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(tiny_thread_pool
        src/pool.c
        src/pool.h)
target_link_libraries(tiny_thread_pool
        pthread)