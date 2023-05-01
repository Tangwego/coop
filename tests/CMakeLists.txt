## Tests executables

aux_source_directory(. TESTS_SRCS)

add_executable(test_oop ${TESTS_SRCS})

target_link_libraries(test_oop coop coop_utils log)

include_directories(${WORK_DIR}/include)
include_directories(${THIRD_PARTY_DIR}/clog)