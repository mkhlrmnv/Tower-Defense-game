cmake_minimum_required(VERSION 3.10)
project(Tower-Defence)

# Specify the C++ standard for your project
set(CMAKE_CXX_STANDARD 11)

# Add the "src" directory to the project for your source files
add_subdirectory(src)

# Add the "tests" directory to the project for your test files
add_subdirectory(tests)

# Optionally, you can create an executable for running the tests
# If main.cpp in the "tests" directory is used to run tests
add_executable(TestRunner tests/main.cpp)
add_executable(MainExec src/main.cpp)

# Link the test runner with the source code and any test libraries
target_link_libraries(TestRunner PUBLIC src_code_library)
target_link_libraries(MainExec PUBLIC src_code_library)


