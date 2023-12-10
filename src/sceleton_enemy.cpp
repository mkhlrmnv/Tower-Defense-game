#include "sceleton_enemy.hpp"
#include "level.hpp"

Sceleton::Sceleton(Level& level, Vector2D& position, int health, int damage, int range, int attack_speed, int type, int speed, int defense, int size) :
    Enemy(level, position, health, damage, range, attack_speed, type, speed, defense, size) {}

bool Sceleton::attack() {
    if (get_reset_counter() >= get_wait_time()) {
        set_attack_speed(get_original_attack_speed());
        set_speed(get_original_speed());
        set_reset_counter(0);
    } else {
        reset_counter_up();
    }
    return false;
}