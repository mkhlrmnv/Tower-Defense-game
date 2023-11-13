# CMakeLists.txt for the "src" directory

# Add all your source files in this directory
set(SRC_FILES
    enemy.cpp
    game.cpp
    level.cpp
    object.cpp
    square.cpp
    tower.cpp
    renderer.cpp
    vector2d.hpp
    # Add all your source files here (excluding headers)
)

# Create a library from the source files
add_library(src_code_library ${SRC_FILES})

# Add the SFML include directories to the library
target_include_directories(src_code_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(src_code_library PUBLIC ${SFML_SOURCE_DIR}/include)

# Add the "src" directory to the include directories for the library
target_include_directories(src_code_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
