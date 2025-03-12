# CMake file for test

add_executable(test "src/main.cpp")

target_link_libraries(
    test
    PRIVATE
        basikgl
)

target_compile_definitions(
    test
    PRIVATE
        ASSETS_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}/assets\"
)