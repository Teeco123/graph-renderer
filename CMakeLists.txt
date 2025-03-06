cmake_minimum_required(VERSION 3.10)
project(GraphRenderer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Specify raylib location (from submodule)
add_subdirectory(external/raylib)

# Add source files
add_executable(GraphRenderer src/main.cpp)

# Link raylib to the project
target_link_libraries(GraphRenderer raylib)
