#ifndef TOWER_HPP
#define TOWER_HPP

#include "object.hpp"

class Tower: public Object {
public:
    Tower(int health, int damage, int range, int attack_speed, Vector2D& position, int price);

    void level_up(int level);

private:
    int _price;
};

#endif