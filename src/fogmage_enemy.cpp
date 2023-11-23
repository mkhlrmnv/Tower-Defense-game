#include "fogmage_enemy.hpp"
#include "level.hpp"

Fog_Mage::Fog_Mage(Level& level, Vector2D& position, int health, int damage, int range, int attack_speed, int type, int speed, int defense) :
    Enemy(level, position, health, damage, range, attack_speed, type, speed, defense) {}

bool Fog_Mage::attack() {
    return false;
}