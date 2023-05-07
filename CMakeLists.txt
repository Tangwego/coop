#######################################################################
#                                                                     #
#    A simple c-oop framework, easy to use and much utils to provide. #
#                                                                     #
#    Author: Wavin Don                                                #
#    Date  : 2023-04-22                                               #
#                                                                     #
#######################################################################
cmake_minimum_required(VERSION 3.23)
project(coop LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(WORK_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BIN_DIR  ${WORK_DIR}/bin)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR})
set(CMAKE_BINARY_DIR               ${BIN_DIR})
set(EXECUTABLE_OUTPUT_PATH         ${BIN_DIR})
set(LIBRARY_OUTPUT_PATH            ${BIN_DIR})

set(THIRD_PARTY_DIR ${WORK_DIR}/third_party)
set(SOURCE_DIR      ${WORK_DIR}/src)
set(TESTS_DIR       ${WORK_DIR}/tests)

add_subdirectory(${THIRD_PARTY_DIR})
add_subdirectory(${SOURCE_DIR})
add_subdirectory(${TESTS_DIR})

