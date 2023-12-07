#include "tower.hpp"

Tower::Tower(Level& current_level, Vector2D& position, int health, int damage, int range, int attack_speed, int type, int price, int level) : 
        Object(current_level, position, health, damage, range, attack_speed, type), _price(price), _level(level) {}

void Tower::level_up() {
    gain_damage(10);
    gain_health(50);
    gain_range(50);
    gain_attack_speed(10);
    set_original_attack_speed(get_attack_speed());
    _level++;
}

int Tower::get_price() {
    return _price;
}

int Tower::get_level() {
    return _level;
}