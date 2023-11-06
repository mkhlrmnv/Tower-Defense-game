#include "basic_tower.hpp"

#include <chrono>
#include <thread>

// Basic_Tower::Basic_Tower()
//     : Tower(100, 20, 3, 100, Vector2D(0, 0), BASIC, 150, 1) {
//     _attack_type_single = true;
// }

Basic_Tower::Basic_Tower(int health, int damage, int range, int attack_speed, Vector2D& position,
        int type, int price, int level, bool attack_type_single) :
        Tower(health, damage, range, attack_speed, position, type, price, level), _attack_type_single(attack_type_single) {}

void Basic_Tower::attack() {
    double multiplier;
    auto closestObjects = distances();

    if (!closestObjects.empty()) {
        if (_attack_type_single && closestObjects[0].first < this->get_range()) {
            multiplier = check_type_multiplier(this, closestObjects[0].second);
            closestObjects[0].second->lose_health(this->get_damage() * multiplier);
        } else {
            for (int i = 0; i < 3; ++i) {
                multiplier = check_type_multiplier(this, closestObjects[i].second);
                if (closestObjects[i].first < this->get_range()) {
                    closestObjects[i].second->lose_health(this->get_damage() * multiplier);
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 - this->get_attack_speed()));
    }
}