#!/bin/bash

branch="3-create-object-class"
files=(
    "src/level.hpp"
    "src/level.cpp"
    "src/attack_types.cpp"
    "src/attack_types.hpp"
    "src/basic_enemy.cpp"
    "src/basic_enemy.hpp"
    "src/level.cpp"
    "src/level.hpp"
    "src/enemy.cpp"
    "src/enemy.hpp"
    "src/tower.cpp"
    "src/tower.hpp"
    "src/object.cpp"
    "src/object.hpp"
    "src/fastboy_enemy.cpp"
    "src/fastboy_enemy.hpp"
    "src/healer_enemy.cpp"
    "src/healer_enemy.hpp"
    "src/fogmage_enemy.cpp"
    "src/fogmage_enemy.hpp"
    "src/repel_tower.cpp"
    "src/repel_tower.hpp"
    "src/sniper_tower.cpp"
    "src/sniper_tower.hpp"
    "src/mud_mage_tower.cpp"
    "src/mud_mage_tower.hpp"
    "src/water_mage_tower.hpp"
    "src/water_mage_tower.cpp"
    "src/boss_enemy.cpp"
    "src/boss_enemy.hpp"
)

for file in "${files[@]}"; do
    git checkout "$branch" -- "$file"
    if [ $? -eq 0 ]; then
        echo "Successfully pulled $file from branch $branch"
    else
        echo "Failed to pull $file from branch $branch"
    fi
done
