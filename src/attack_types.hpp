#ifndef ATTACK_TYPES_HPP
#define ATTACK_TYPES_HPP

#include "enemy.hpp"
#include "tower.hpp"

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

double check_type_multiplier(Tower* tower, Enemy* enemy) {
    int critical = 2;
    int neutral = 1;
    // int weak = 0.5;

    // Handle towers vs enemies
    if (tower->get_type() == SNIPER && (enemy->get_type() == FAT || enemy->get_type() == BOSS)) {
        return critical;
    } else if (tower->get_type() == WATER && enemy->get_type() == RPG) {
        return critical;
    } else if (tower->get_type() == MAGE && (enemy->get_type() == FAT || enemy->get_type() == BOSS)) {
        return critical;
    } else if (tower->get_type() == REPEL && (enemy->get_type() == FOG || enemy->get_type() == HEAL)) {
        return critical;
    }

    // Handle enemies vs towers
    if ((enemy->get_type() == FAT || enemy->get_type() == BOSS) && tower->get_type() == WATER) {
        return critical;
    } else if (enemy->get_type() == RPG && (tower->get_type() == BASIC || tower->get_type() == MAGE)) {
        return critical;
    }

    return neutral;
}

#endif