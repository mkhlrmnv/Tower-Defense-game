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
)

for file in "${files[@]}"; do
    git checkout "$branch" -- "$file"
    if [ $? -eq 0 ]; then
        echo "Successfully pulled $file from branch $branch"
    else
        echo "Failed to pull $file from branch $branch"
    fi
done
