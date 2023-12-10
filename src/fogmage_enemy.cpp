#include "fogmage_enemy.hpp"
#include "level.hpp"

Fog_Mage::Fog_Mage(Level& level, Vector2D& position, int health, int damage, int range, int attack_speed, int type, int speed, int defense, int size) :
    Enemy(level, position, health, damage, range, attack_speed, type, speed, defense, size) {}

bool Fog_Mage::attack() {
    if (get_reset_counter() >= get_wait_time()) {
        set_attack_speed(get_original_attack_speed());
        set_speed(get_original_speed());
        set_reset_counter(0);
    } else {
        reset_counter_up();
    }

    Level& level_reference = get_level_reference();

    if (!level_reference.get_towers().empty()) {
        int counter = 0;
        for (auto& tower : level_reference.get_towers()) {

            double dist = this->distance_to(tower->get_position());

            if (dist <= this->get_range()) {
                if (get_attack_counter() <= get_attack_speed()) {
                    attack_counter_up();
                    set_state(State::none);
                    std::cout << "uuuuuu" << std::endl;
                    return false;
                } else {
                    set_attack_counter(0);
                    if (tower->get_attack_speed() != tower->get_original_attack_speed() + 1) {
                        tower->lose_attack_speed(tower->get_attack_speed() / 2);
                    }
                    counter++;

                    if (counter >= 4) {
                        return true;
                    }
                }
            }
            std::cout << "aaaaaaa" << std::endl;
        }
    }
    set_state(State::none);
    return false;
}