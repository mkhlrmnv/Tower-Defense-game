#include "basic_enemy.hpp"
#include "level.hpp"

Basic_Enemy::Basic_Enemy(Level& level, int health, int damage, int range, int attack_speed, Vector2D& position, int type, int speed, int defense) :
    Enemy(level, health, damage, range, attack_speed, position, type, speed, defense) {}

void Basic_Enemy::attack() {
    double multiplier;
    Level& level_reference = get_level_reference();

    if (!level_reference.get_towers().empty()) {
        for (auto& tower : level_reference.get_towers()) {

            double dist = this->distance_to(tower->get_position());

            if (dist <= this->get_range()) {
                multiplier = check_type_multiplier(tower, this);
                tower->lose_health(this->get_damage() * multiplier);
                break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(this->get_attack_speed()));
    }
}