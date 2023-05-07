## Tests executables
project(test)

set(TEST_DIR ${WORK_DIR}/tests)
set(CMAKE_EXE_LINKER_FLAGS_DEBUG " -T ${TEST_DIR}/test.lds -static")

aux_source_directory(. TESTS_SRCS)

add_executable(test_oop ${TESTS_SRCS})

target_link_libraries(test_oop coop coop_utils log gtest)

include_directories(${WORK_DIR}/include)
include_directories(${THIRD_PARTY_DIR}/clog)
include_directories(${THIRD_PARTY_DIR}/googletest/googletest/include)