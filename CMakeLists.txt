cmake_minimum_required(VERSION 3.10)
project(Tower-Defence)

# Specify the C++ standard for your project
set(CMAKE_CXX_STANDARD 11)

# Add the "src" directory to the project for your source files
add_subdirectory(src)

# Add the "tests" directory to the project for your test files
add_subdirectory(tests)

# uses SFML
set(GAME_CLASS_SOURCE src/game.cpp)

set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

set(CMAKE_BUILD_TYPE Debug) # this adds debug information and disables compiler optimizations


# Optionally, you can create an executable for running the tests
# If main.cpp in the "tests" directory is used to run tests
add_executable(TestRunner tests/main.cpp ${GAME_CLASS_SOURCE})
add_executable(MainExec src/main.cpp ${GAME_CLASS_SOURCE})

target_link_libraries(MainExec PRIVATE sfml-graphics sfml-window sfml-system)
target_link_libraries(TestRunner PRIVATE sfml-graphics sfml-window sfml-system)



# Link the test runner with the source code and any test libraries
target_link_libraries(TestRunner PUBLIC src_code_library)
target_link_libraries(MainExec PUBLIC src_code_library)
