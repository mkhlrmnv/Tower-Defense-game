#include "tower.hpp"

Tower::Tower(Level& current_level, Vector2D& position, int health, int damage, int range, int attack_speed, int type, int price, int level) : 
        Object(current_level, position, health, damage, range, attack_speed, type), _price(price), _level(level) {}

void Tower::level_up() {
    gain_damage(10 * _level);
    gain_health(30 * _level);
    gain_range(100 * _level);
    gain_attack_speed(2 * _level);
    _level++;
}

int Tower::get_price() {
    return _price;
}

int Tower::get_level() {
    return _level;
}