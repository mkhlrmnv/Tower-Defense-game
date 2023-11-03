#ifndef BASIC_TOWER_SINGLE_HPP
#define BASIC_TOWER_SINGLE_HPP

#include "tower.hpp"

class Basic_Tower: public Tower {
public:
    Basic_Tower(int health, int damage, int range, int attack_speed, Vector2D& position, int type, int price, bool attack_type_single);

    void attack();

private:
    bool _attack_type_single;
};

#endif