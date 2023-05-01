aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} COOP_UTILS_SRCS)
add_library(coop_utils SHARED ${COOP_UTILS_SRCS})
include_directories(${WORK_DIR}/include)
