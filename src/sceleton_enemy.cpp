#include "sceleton_enemy.hpp"
#include "level.hpp"

Sceleton::Sceleton(Level& level, Vector2D& position, int health, int damage, int range, int attack_speed, int type, int speed, int defense, int size) :
    Enemy(level, position, health, damage, range, attack_speed, type, speed, defense, size) {}

bool Sceleton::attack() {
    return false;
}