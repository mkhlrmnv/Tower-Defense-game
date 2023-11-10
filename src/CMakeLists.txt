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

# Add the "src" directory to the include directories for the library
target_include_directories(src_code_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Create an executable for your main program (main.cpp)
#add_executable(Main main.cpp)  # Ensure you have a main.cpp with your main function

# Link the main executable with the source code library
#target_link_libraries(Main src_code_library)