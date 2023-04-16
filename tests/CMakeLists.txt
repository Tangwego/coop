add_executable(test_string main.c string.c)

target_link_libraries(test_string coop)

include_directories(${WORKSPACE_DIR}/include)