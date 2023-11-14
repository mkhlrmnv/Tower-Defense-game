#include "basic_tower.hpp"

Basic_Tower::Basic_Tower(Level& current_level, int health, int damage, int range, int attack_speed, Vector2D& position,
        int type, int price, int level, bool attack_type_single) :
        Tower(current_level, health, damage, range, attack_speed, position, type, price, level), _attack_type_single(attack_type_single) {}

void Basic_Tower::attack() {
    double multiplier;
    Level& level_reference = get_level_reference();

    if (!level_reference.get_enemies().empty()) {
        if (_attack_type_single) {
            for (auto& enemy : level_reference.get_enemies()) {

                double dist = this->distance_to(enemy->get_position());

                if (dist <= this->get_range()) {
                    multiplier = check_type_multiplier(this, enemy);
                    enemy->lose_health(this->get_damage() * multiplier);
                    break;
                }
            }
        } else {
            int counter = 0;
            for (auto& enemy : level_reference.get_enemies()) {

                double dist = this->distance_to(enemy->get_position());

                if (dist <= this->get_range()) {
                    multiplier = check_type_multiplier(this, enemy);
                    enemy->lose_health(this->get_damage() * multiplier);
                    counter++;
                }

                if (counter >= 3) {
                    break;
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(this->get_attack_speed()));
    }
}