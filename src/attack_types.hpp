#ifndef ATTACK_TYPES_HPP
#define ATTACK_TYPES_HPP

#include <string>
#include <iostream>

// #include "enemy.hpp"
// #include "tower.hpp"

class Tower;
class Enemy;


// TODO: WaterMage and MudMage
namespace ObjectTypes
{ 
    enum Enemies{
        NoobSkeleton_NoAttack,
        NoobDemon_CanAttack,
        FastBoy,
        FogMage,
        HealerPriest,
        InfernoMage,
        TankOrc,
        BossKnight,
    };
    enum Towers{
        AoeTower,
        ArcherTower,
        MudMageTower,
        RepelMageTower,
        SniperTower,
        WaterMageTower,
    };
}

double check_type_multiplier(Tower* tower, Enemy* enemy);


#endif