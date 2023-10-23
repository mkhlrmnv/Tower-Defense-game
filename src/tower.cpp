#include "tower.hpp"

Tower::Tower(int health, int damage, int range, int attack_speed, Vector2D& position, int price) : 
            Object(health, damage, range, attack_speed, position), _price(price) {}

void Tower::level_up(int level) {
    gain_attack_speed(20 * level);
    gain_health(50 * level);
    gain_range(5 * level);
    gain_attack_speed(10 * level);
}