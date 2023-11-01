cmake_minimum_required(VERSION 3.11.0)
project(test VERSION 0.1.0)

enable_language(CXX)

# Use C++ standard version 17
set(CMAKE_CXX_STANDARD 17)
# Produce non-optimized code with debug symbols
set(CMAKE_BUILD_TYPE Debug)

message(STATUS "BUILD directory is ${CMAKE_BINARY_DIR}")
message(STATUS "SRC directory is ${CMAKE_SOURCE_DIR}")

# Add your source files (only .cpp files) to the source file list
set(GAME_SOURCE_FILES
    src/level.cpp
    src/square.cpp
    tests/main.cpp  # Include the main.cpp for your executable
)

# Create a separate list for header files (only .hpp files)
set(GAME_HEADER_FILES
    src/level.hpp
    src/square.hpp
    src/Vector2d.hpp
)

# Add the executable target
add_executable(Game ${GAME_SOURCE_FILES})

# Include the directory with header files so that you can use #include "header.hpp" in your source files
target_include_directories(Game PRIVATE ${CMAKE_SOURCE_DIR})

# Optionally, you can specify additional directories for header files if needed
# target_include_directories(Game PRIVATE ${CMAKE_SOURCE_DIR}/some_other_directory)

