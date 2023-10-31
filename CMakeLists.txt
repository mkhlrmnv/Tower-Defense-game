cmake_minimum_required(VERSION 3.16) # not sure about this

project(tower_defence)

# Set the name of the executable to be produced
set(EXECUTABLE_NAME game)

include_directories(src)

set(CMAKE_CXX_STANDARD 17)

# TODO: Add all .cpp files under src/ directory 
set(SOURCES 
    src/game.cpp
)

set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# add the cpp files to the files list that will be included into the built
add_executable(${EXECUTABLE_NAME} ${SOURCES})

# set the build target configuration
set(CMAKE_BUILD_TYPE Debug) # this adds debug information and disables compiler optimizations

target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-window sfml-system)

# For installing targets (not mandatory)
install (TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

