#include "fastboy_enemy.hpp"
#include "level.hpp"

Fast_Boy::Fast_Boy(Level& level, Vector2D& position, int health, int damage, int range, int attack_speed, int type, int speed, int defense, int size) :
    Enemy(level, position, health, damage, range, attack_speed, type, speed, defense, size) {}

bool Fast_Boy::attack() {
    if (get_reset_counter() >= 50) {
        set_attack_speed(get_original_attack_speed());
        set_speed(get_original_speed());
        set_reset_counter(0);
    } else {
        reset_counter_up();
    }
    return false;
}