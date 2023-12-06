#include "repel_tower.hpp"

Repel_Tower::Repel_Tower(Level& current_level, Vector2D& position, int health, int damage, int range,
        int attack_speed, int type, int price, int level) :

        Tower(current_level, position, health, damage, range, attack_speed, type, price, level) {}

bool Repel_Tower::attack() {
    if (get_reset_counter() >= get_wait_time()) {
        set_attack_speed(get_original_attack_speed());
        set_reset_counter(0);
    } else {
        reset_counter_up();
    }

    bool has_attacked;
    double multiplier;
    Level& level_reference = get_level_reference();

    if (!level_reference.get_enemies().empty()) {
        int counter = 0;
        for (auto& enemy : level_reference.get_enemies()) {

            double dist = this->distance_to(enemy->get_position());

            if (dist <= this->get_range()) {
                if (get_attack_counter() >= get_attack_speed()) {
                    attack_counter_up();
                    set_state(State::none);
                    return false;
                } else {
                    set_attack_counter(0);
                    multiplier = check_type_multiplier(this, enemy);
                    enemy->lose_health(this->get_damage() * multiplier);

                    if (enemy->get_speed() != 0) {
                        enemy->set_speed(0);
                    }

                    if (this->get_position().y > level_reference.get_enemies()[0]->get_position().y){
                        set_state(State::attacking_left);
                        has_attacked = true;
                    } else {
                        set_state(State::attacking_right);
                        has_attacked = true;
                    }
                    
                    counter++;
                    if (counter >= 3) {
                        return true;
                        break;
                    }
                }
            }
        }
    }
    if (!has_attacked) {
        set_state(State::none);
    } else {
        return true;
    }

    has_attacked = false;
    return false;
}