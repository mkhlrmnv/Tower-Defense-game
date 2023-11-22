#include "basic_tower.hpp"

Basic_Tower::Basic_Tower(Level& current_level, Vector2D& position, int health, int damage, int range,
        int attack_speed, int type, int price, int level, bool attack_type_single) :

        Tower(current_level, position, health, damage, range, attack_speed, type, price, level), _attack_type_single(attack_type_single) {}

bool Basic_Tower::attack() {
    double multiplier;
    Level& level_reference = get_level_reference();

    if (!level_reference.get_enemies().empty()) {
        if (_attack_type_single) {
            for (auto& enemy : level_reference.get_enemies()) {

                double dist = this->distance_to(enemy->get_position());

                if (dist <= this->get_range()) {
                    multiplier = check_type_multiplier(this, enemy);
                    enemy->lose_health(this->get_damage() * multiplier);
                    if (this->get_position().y > enemy->get_position().y){
                        set_state(State::attacking_left);
                    } else {
                        set_state(State::attacking_right);
                    }
                    return true;
                    break;
                }
            }
        } else {
            int counter = 0;
            if (this->get_position().y > level_reference.get_enemies()[0]->get_position().y){
                set_state(State::attacking_left);
            } else {
                set_state(State::attacking_right);
            }
            for (auto& enemy : level_reference.get_enemies()) {

                double dist = this->distance_to(enemy->get_position());

                if (dist <= this->get_range()) {
                    multiplier = check_type_multiplier(this, enemy);
                    enemy->lose_health(this->get_damage() * multiplier);
                    counter++;
                }

                if (counter >= 3) {
                    return true;
                    break;
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(this->get_attack_speed()));
    }
    set_state(State::none);
    return false;
}