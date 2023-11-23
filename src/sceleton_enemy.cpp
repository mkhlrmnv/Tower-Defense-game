#include "sceleton_enemy.hpp"
#include "level.hpp"

Basic_Enemy::Basic_Enemy(Level& level, Vector2D& position, int health, int damage, int range, int attack_speed, int type, int speed, int defense) :
    Enemy(level, position, health, damage, range, attack_speed, type, speed, defense) {}

bool Basic_Enemy::attack() {
    return false;
}