cmake_minimum_required(VERSION 3.24.0)

project(BasikGL)

# Some basic options
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set GLFW options
include_directories("glfw/include")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
add_subdirectory("glfw")

# Set GLM options
include_directories("glm")
set(GLM_TEST_ENABLE OFF CACHE BOOL "" FORCE)
add_subdirectory("glm")

# Add GLAD
include_directories("glad/include")
add_subdirectory("glad")

# Add stb_image
include_directories("stb_image")
add_subdirectory("stb_image")

# Add tiny_obj_loader
include_directories("tiny_obj_loader")
add_subdirectory("tiny_obj_loader")

# Set some project properties
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

# Add src
include_directories("include")
include_directories("src")
add_subdirectory("src")

# Add examples
add_subdirectory("examples")