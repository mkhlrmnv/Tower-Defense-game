#include "demon_enemy.hpp"
#include "level.hpp"

Basic_Enemy::Basic_Enemy(Level& level, Vector2D& position, int health, int damage, int range, int attack_speed, int type, int speed, int defense) :
    Enemy(level, position, health, damage, range, attack_speed, type, speed, defense) {}

bool Basic_Enemy::attack() {
    double multiplier;
    Level& level_reference = get_level_reference();

    if (!level_reference.get_towers().empty()) {
        for (auto& tower : level_reference.get_towers()) {

            double dist = this->distance_to(tower->get_position());

            if (dist <= this->get_range()) {
                multiplier = check_type_multiplier(tower, this);
                tower->lose_health(this->get_damage() * multiplier);
                if (this->get_position().y > tower->get_position().y){
                    set_state(State::attacking_left);
                } else {
                    set_state(State::attacking_right);
                }
                return true;
                break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(this->get_attack_speed()));
    }
    set_state(State::none);
    return false;
}