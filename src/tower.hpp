#ifndef TOWER_HPP
#define TOWER_HPP

#include "object.hpp"

class Tower: public Object {
public:
    Tower(Level& current_level, Vector2D& position, int health, int damage, int range, int attack_speed, int type, int price, int level);

    ~Tower() { }

    void level_up();

    int get_price();

private:
    int _price;
    int _level;
};
#endif