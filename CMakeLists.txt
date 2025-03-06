# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Define the project name and the programming language used
project(MyProject LANGUAGES CXX)

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 17)

# Add an executable target with the specified source files
add_executable(MyExecutable main.cpp)

# Optionally, specify the output directory for executables
set_target_properties(MyExecutable PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
