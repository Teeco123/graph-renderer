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
include_directories(src)

# Automatically add all .cpp files in the src directory
file(GLOB SOURCES src/*.cpp)

# Add source files
add_executable(GraphRenderer ${SOURCES})

# Link raylib and raygui to the project
target_link_libraries(GraphRenderer raylib)

# Set the output directory for the executable to the "bin" folder
set_target_properties(GraphRenderer PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
