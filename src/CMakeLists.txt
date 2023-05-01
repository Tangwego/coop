## common sources
add_subdirectory(utils)

aux_source_directory(. COOP_CLASS_SRCS)
add_library(coop SHARED ${COOP_CLASS_SRCS})
include_directories(${WORK_DIR}/include)
