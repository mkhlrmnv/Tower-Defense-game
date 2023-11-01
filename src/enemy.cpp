#include "enemy.hpp"

Enemy::Enemy(int health, int damage, int range, int attack_speed, Vector2D& position, int speed, int defense) : 
            Object(health, damage, range, attack_speed, position), _speed(speed), _defense(defense) {}

void Enemy::move(Vector2D targetPosition) {
    set_position(targetPosition);
}
