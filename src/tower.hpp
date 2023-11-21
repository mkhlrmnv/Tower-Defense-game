#ifndef TOWER_HPP
#define TOWER_HPP

#include "object.hpp"

class Tower: public Object {
public:
    Tower(Level& current_level, int health, int damage, int range, int attack_speed, Vector2D position, int type, int price, int level);

    ~Tower() { }

    void level_up();

private:
    int _price;
    int _level;
};

#endif