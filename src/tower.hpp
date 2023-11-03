#ifndef TOWER_HPP
#define TOWER_HPP

#include "object.hpp"

class Tower: public Object {
public:
    Tower(int health, int damage, int range, int attack_speed, Vector2D& position, int type, int price) : 
            Object(health, damage, range, attack_speed, position, type), _price(price) {}

    void level_up(int level) {
        gain_attack_speed(20 * level);
        gain_health(50 * level);
        gain_range(5 * level);
        gain_attack_speed(10 * level);
    }

private:
    int _price;
};

#endif