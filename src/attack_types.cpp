#include "attack_types.hpp"
#include "tower.hpp"
#include "enemy.hpp"

double check_type_multiplier(Tower* tower, Enemy* enemy){
    int critical = 2;
    int neutral = 1;
    // int weak = 0.5;

    // Handle towers vs enemies
    if (tower->get_type() == ObjectTypes::SniperTower && (enemy->get_type() == ObjectTypes::TankOrc || enemy->get_type() == ObjectTypes::BossKnight)) {
        return critical;
    } else if (tower->get_type() == ObjectTypes::WaterMageTower && enemy->get_type() == ObjectTypes::InfernoMage) {
        return critical;
    } else if (tower->get_type() == ObjectTypes::MudMageTower && (enemy->get_type() == ObjectTypes::TankOrc || enemy->get_type() == ObjectTypes::BossKnight)) {
        return critical;
    } else if (tower->get_type() == ObjectTypes::RepelMageTower && (enemy->get_type() == ObjectTypes::FogMage || enemy->get_type() == ObjectTypes::HealerPriest)) {
        return critical;
    }

    // Handle enemies vs towers
    if ((enemy->get_type() == ::ObjectTypes::TankOrc || enemy->get_type() == ObjectTypes::BossKnight) && tower->get_type() == ObjectTypes::WaterMageTower) {
        return critical;
    } else if (enemy->get_type() == ObjectTypes::InfernoMage && (tower->get_type() == ObjectTypes::ArcherTower || tower->get_type() == ObjectTypes::AoeTower || tower->get_type() == ObjectTypes::MudMageTower)) {
        return critical;
    }

    return neutral;
}