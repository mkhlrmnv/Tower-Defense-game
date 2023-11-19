#include "attack_types.hpp"
#include "tower.hpp"
#include "enemy.hpp"

double check_type_multiplier(Tower* tower, Enemy* enemy){
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

// TODO: Finish when textures are fully done;
std::string get_file_enemy(Enemy* enemy){
    switch (enemy->get_type())
    {
    case BOSS:
        return "assets/textures/BossKnight/BossKnight_Right.png";
    case NEUTRAL:
        return "assets/textures/TankOrc/TankOrc.png";
    default:
        break;
    }
    return "";
}
std::string get_file_tower(Tower* tower){
    switch (tower->get_type())
    {
    case BASIC: 
        return "assets/textures/ArcherTower/ArcherTower_Right.png";
    case SNIPER:
        return "assets/textures/SniperTower/SniperTower_Right.png";
    default:
        break;
    }
    return "";
}