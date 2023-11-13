#include "basic_enemy.hpp"

// Basic_Enemy::Basic_Enemy() :
//     Enemy(50, 10, 20, 1000, Vector2D(0,0), NEUTRAL, 10, 5) {}

Basic_Enemy::Basic_Enemy(Level& level, int health, int damage, int range, int attack_speed, Vector2D& position, int type, int speed, int defense) :
    Enemy(level, health, damage, range, attack_speed, position, type, speed, defense) {}

void Basic_Enemy::attack() {
    double multiplier;
    Level& level_reference = get_level_reference();

    if (!level_reference.get_towers().empty()) {
        double dist = this->distance_to(level_reference.get_towers()[0]->get_position());
        if (dist <= this->get_range()) {
            multiplier = check_type_multiplier(level_reference.get_towers()[0], this);
            level_reference.get_towers()[0]->lose_health(this->get_damage() * multiplier);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(this->get_attack_speed()));
    }
}