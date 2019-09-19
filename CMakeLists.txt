cmake_minimum_required(VERSION 3.14)
project(GetNextLine)

set(CMAKE_C_STANDARD 99)

include_directories(libft)

set(SOURCES get_next_line.c)

set (HEADER get_next_line.h)

add_executable(GetNextLine ${SOURCES} ${HEADERS})

add_subdirectory(libft)