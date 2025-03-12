# CMake file for examples

include_directories("../include/")
add_definitions(-DBSKGL_EXAMPLES_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\")

add_subdirectory(test)
add_subdirectory(triangle)