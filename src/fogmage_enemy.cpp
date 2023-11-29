#include "fogmage_enemy.hpp"
#include "level.hpp"

Fog_Mage::Fog_Mage(Level& level, Vector2D& position, int health, int damage, int range, int attack_speed, int type, int speed, int defense) :
    Enemy(level, position, health, damage, range, attack_speed, type, speed, defense) {}

bool Fog_Mage::attack() {
    Level& level_reference = get_level_reference();

    if (!level_reference.get_towers().empty()) {
        int counter = 0;
        for (auto& tower : level_reference.get_towers()) {

            double dist = this->distance_to(tower->get_position());

            if (dist <= this->get_range()) {
                tower->lose_attack_speed(1);
                counter++;
            }

            if (counter >= 4) {
                return true;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(this->get_attack_speed()));
    }
    set_state(State::none);
    return false;
}