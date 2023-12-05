#ifndef ATTACK_TYPES_HPP
#define ATTACK_TYPES_HPP

#include <string>
#include <iostream>

class Tower;
class Enemy;

/**
 * @brief Namespace containing enums for different enemy and tower types.
 */
namespace ObjectTypes {
    /**
     * @brief Enums representing different types of enemies.
     */
    enum Enemies {
        NoobSkeleton_NoAttack,
        NoobDemon_CanAttack,
        FastBoy,
        FogMage,
        HealerPriest,
        InfernoMage,
        TankOrc,
        BossKnight,
    };

    /**
     * @brief Enums representing different types of towers.
     */
    enum Towers {
        AoeTower,
        ArcherTower,
        MudMageTower,
        RepelMageTower,
        SniperTower,
        WaterMageTower,
    };
}

/**
 * @brief Function to check the type multiplier between a tower and an enemy.
 * 
 * @param tower Pointer to the Tower object.
 * @param enemy Pointer to the Enemy object.
 * @return Double representing the type multiplier between the tower and enemy.
 */
double check_type_multiplier(Tower* tower, Enemy* enemy);

#endif