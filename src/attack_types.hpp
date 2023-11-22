#ifndef ATTACK_TYPES_HPP
#define ATTACK_TYPES_HPP

#include <string>
#include <iostream>

// #include "enemy.hpp"
// #include "tower.hpp"

class Tower;
class Enemy;


// TODO: WaterMage and MudMage
enum TOWERTYPE {
    BASIC,
    SNIPER,
    WATER,
    MAGE,
    REPEL
};

enum ENEMYTYPE {
    NEUTRAL,
    HEAL,
    FOG,
    FAT,
    BOSS,
    RPG
};

double check_type_multiplier(Tower* tower, Enemy* enemy);

std::string get_file_enemy(Enemy* enemy);

std::string get_file_tower(Tower* tower);

#endif