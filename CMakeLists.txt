cmake_minimum_required(VERSION 3.23)
project(coop C)

set(CMAKE_C_STANDARD 99)
set(WORKSPACE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

aux_source_directory(src ALL_SRCS)

add_library(coop src/class.c)

add_subdirectory(${WORKSPACE_DIR}/tests)
#add_executable(coop tests/main.c tests/string.c ${ALL_SRCS})

include_directories(${WORKSPACE_DIR}/include)