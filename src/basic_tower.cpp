#include "basic_tower.hpp"

Basic_Tower::Basic_Tower(int health, int damage, int range, int attack_speed, Vector2D& position,
        int type, int price, bool attack_type_single) :
        Tower(health, damage, range, attack_speed, position, type, price), _attack_type_single(attack_type_single) {}

void Basic_Tower::attack() {
    double multiplier;
    if (_attack_type_single) {
        Object& target = single();
        multiplier = check_type_multiplier(this, target);
        target.lose_health(this->get_damage() * multiplier);
    } else {
        for (Object& enemy : multiple()) {
            multiplier = check_type_multiplier(this, enemy);
            enemy.lose_health(this->get_damage()* multiplier);
        }
    }
}