#include "healer_enemy.hpp"
#include "level.hpp"

Healer::Healer(Level& level, Vector2D& position, int health, int damage, int range, int attack_speed, int type, int speed, int defense, int size) :
    Enemy(level, position, health, damage, range, attack_speed, type, speed, defense, size) {}

bool Healer::attack() {
    Level& level_reference = get_level_reference();

    if (!level_reference.get_enemies().empty()) {
        int counter = 0;
        for (auto& enemy : level_reference.get_enemies()) {

            double dist = this->distance_to(enemy->get_position());

            if (dist <= this->get_range()) {

                if (this->get_position().y > level_reference.get_enemies()[0]->get_position().y){
                    set_state(State::attacking_left);
                } else {
                    set_state(State::attacking_right);
                }

                if (get_attack_counter() <= get_attack_speed()) {
                    attack_counter_up();
                    set_state(State::none);
                    return false;
                } else {
                    set_attack_counter(0);
                    enemy->gain_health(this->get_damage());
                    counter++;
                    if (counter >= 4) {
                        return true;
                        break;
                    }
                }
            }
        }
    }
    set_state(State::none);
    return false;
}