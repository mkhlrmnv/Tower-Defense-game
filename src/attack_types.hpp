#ifndef ATTACK_TYPES_HPP
#define ATTACK_TYPES_HPP

// #include "enemy.hpp"
// #include "tower.hpp"

class Tower;
class Enemy;

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

#endif