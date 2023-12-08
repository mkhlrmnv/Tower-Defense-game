# CMakeLists.txt for the "src" directory

# Add all your source files in this directory
set(SRC_FILES
    enemy.cpp
    basic_enemy.cpp
    basic_tower.cpp
    level.cpp
    object.cpp
    square.cpp
    tower.cpp
    attack_types.cpp
    vector2d.hpp
    archer_tower.cpp
    aoe_tower.cpp
    boss_enemy.cpp
    demon_enemy.cpp
    fastboy_enemy.cpp
    fogmage_enemy.cpp
    healer_enemy.cpp
    inferno_enemy.cpp
    repel_tower.cpp
    sceleton_enemy.cpp
    sniper_tower.cpp
    tank_enemy.cpp
    boss_enemy.cpp
    mud_mage_tower.cpp
    water_mage_tower.cpp
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