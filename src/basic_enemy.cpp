#include "basic_enemy.hpp"

Basic_Enemy::Basic_Enemy() :
    Enemy(50, 10, 20, 100, Vector2D(0,0), NEUTRAL, 10, ) {}

Basic_Enemy::Basic_Enemy(int health, int damage, int range, int attack_speed, Vector2D& position, int type, int speed, int defense) :
    Enemy(health, damage, range, attack_speed, position, type, speed, defense) {}

