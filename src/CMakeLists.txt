# CMake file for src

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Determine build type and set flags
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(BSK_DEBUG)
    add_compile_options(-g)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_definitions(BSK_RELEASE)
    add_compile_options(-O2)
elseif(CMAKE_BUILD_TYPE STREQUAL "Distribution")
    add_compile_definitions(BSK_DISTRIBUTION)
    add_compile_options(-O3 -s)
endif()

# Determine platform
if(WIN32)
    add_compile_definitions(BSK_PLATFORM_WINDOWS)
    set(PLATFORM_LIBS kernel32.lib user32.lib gdi32.lib opengl32.lib)
elseif(APPLE)
    add_compile_definitions(BSK_PLATFORM_MACOS)
    find_library(COCOA_LIBRARY Cocoa)
    find_library(OPENGL_LIBRARY OpenGL)
    find_library(IOKIT_LIBRARY IOKit)
    find_library(COREVIDEO_LIBRARY CoreVideo)
    set(PLATFORM_LIBS ${COCOA_LIBRARY} ${OPENGL_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY})
elseif(UNIX)
    add_compile_definitions(BSK_PLATFORM_LINUX)
    find_package(OpenGL REQUIRED)
    set(PLATFORM_LIBS ${OPENGL_LIBRARIES} pthread dl X11)
endif()

# Set library type (STATIC/SHARED)
option(BSK_BUILD_STATIC "Build BasikGL as a static library" ON)
if(BSK_BUILD_STATIC)
    add_compile_definitions(BSK_STATIC)
    set(LIB_TYPE STATIC)
else()
    add_compile_definitions(BSK_DYNAMIC)
    set(LIB_TYPE SHARED)
endif()

# Add source files
file(GLOB_RECURSE SOURCES "*.cpp" "*.h")

# Create library target
add_library(basikgl ${LIB_TYPE} ${SOURCES})

# Include directories
target_include_directories(basikgl PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(basikgl PUBLIC glfw glm stb_image tiny_obj_loader glad ${PLATFORM_LIBS})

# Define macro for current directory
target_compile_definitions(basikgl PRIVATE BSK_CURRENT_DIR="${CMAKE_CURRENT_SOURCE_DIR}" BSK_SOURCE_FILE)

# Added source files
message(${SOURCES})