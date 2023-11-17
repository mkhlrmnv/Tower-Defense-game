#include "enemy.hpp"

Enemy::Enemy(Level& level, int health, int damage, int range, int attack_speed, Vector2D position, int type, int speed, int defense) : 
            Object(level, health, damage, range, attack_speed, position, type), _speed(speed), _defense(defense) {}

int Enemy::get_speed() const {
    return _speed;
}

int Enemy::get_defense() const {
    return _defense;
}

std::vector<Vector2D> Enemy::get_route() const{
    return _route;
}

void Enemy::set_route_position(Vector2D position) {
    _route.push_back(position);
}

Vector2D Enemy::get_prev_pos(){
    return _prev_pos;
}

void Enemy::set_prev_pos(Vector2D pos){
    _prev_pos = pos;
}