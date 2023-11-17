#include "tower.hpp"

Tower::Tower(Level& current_level, int health, int damage, int range, int attack_speed, Vector2D position, int type, int price, int level) : 
        Object(current_level, health, damage, range, attack_speed, position, type), _price(price), _level(level) {}

void Tower::level_up() {
    gain_damage(10 * _level);
    gain_health(50 * _level);
    gain_range(5 * _level);
    gain_attack_speed(150 * _level);
}