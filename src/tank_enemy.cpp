#include "tank_enemy.hpp"
#include "level.hpp"

Tank::Tank(Level& level, Vector2D& position, int health, int damage, int range, int attack_speed, int type, int speed, int defense, int size) :
    Enemy(level, position, health, damage, range, attack_speed, type, speed, defense, size) {}

bool Tank::attack() {
    double multiplier;
    Level& level_reference = get_level_reference();

    if (!level_reference.get_towers().empty()) {
        for (auto& tower : level_reference.get_towers()) {

            double dist = this->distance_to(tower->get_position());

            if (dist <= this->get_range()) {
                if (get_attack_counter() <= get_attack_speed()) {
                    attack_counter_up();
                    set_state(State::none);
                    return false;
                } else {
                    set_attack_counter(0);
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
        }
    }
    set_state(State::none);
    return false;
}