cmake_minimum_required(VERSION 3.10)
project(GraphRenderer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Specify raylib location (from submodule)
add_subdirectory(external/raylib)

# Add raygui location (adjust the path as needed)
include_directories(external/raygui/src)
include_directories(external/raygui/styles/cyber)

# Add source files
add_executable(GraphRenderer src/main.cpp)

# Link raylib and raygui to the project
target_link_libraries(GraphRenderer raylib)

# Set the output directory for the executable to the "bin" folder
set_target_properties(GraphRenderer PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
