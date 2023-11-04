#include "basic_tower.hpp"

Basic_Tower::Basic_Tower(int health, int damage, int range, int attack_speed, Vector2D& position,
        int type, int price, bool attack_type_single) :
        Tower(health, damage, range, attack_speed, position, type, price), _attack_type_single(attack_type_single) {}

void Basic_Tower::attack() {
    double multiplier;
    if (!distances().empty()) {
        if (_attack_type_single) {
            multiplier = check_type_multiplier(this, distances()[0]);
            distances()[0].lose_health(this->get_damage() * multiplier);
        } else {
            for (int i = 0; i < 3; ++i) {
                multiplier = check_type_multiplier(this, distances()[i]);
                distances()[i].lose_health(this->get_damage()* multiplier);
            }
        }
    }
}