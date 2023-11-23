#include "healer_enemy.hpp"
#include "level.hpp"

Healer::Healer(Level& level, Vector2D& position, int health, int damage, int range, int attack_speed, int type, int speed, int defense) :
    Enemy(level, position, health, damage, range, attack_speed, type, speed, defense) {}

bool Healer::attack() {
    return false;
}