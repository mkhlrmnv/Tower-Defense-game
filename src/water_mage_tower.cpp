#include "water_mage_tower.hpp"

Water_Mage_Tower::Water_Mage_Tower(Level& current_level, Vector2D& position, int health, int damage, int range,
        int attack_speed, int type, int price, int level) :

        Tower(current_level, position, health, damage, range, attack_speed, type, price, level) {}

bool Water_Mage_Tower::attack() {
    double multiplier;
    Level& level_reference = get_level_reference();

    if (!level_reference.get_enemies().empty()) {
        for (auto& enemy : level_reference.get_enemies()) {

            double dist = this->distance_to(enemy->get_position());

            if (dist <= this->get_range()) {
                if (get_attack_counter() <= get_attack_speed()) {
                    attack_counter_up();
                } else {
                    set_attack_counter(0);
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
        }
    }
    set_state(State::none);
    return false;
}