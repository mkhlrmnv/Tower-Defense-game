#ifndef BASIC_TOWER_HPP
#define BASIC_TOWER_HPP

#include "tower.hpp"
#include "attack_types.hpp"
#include "level.hpp"

class Basic_Tower: public Tower {
public:

    Basic_Tower(Level& current_level, int health, int damage, int range, int attack_speed, Vector2D& position, int type, int price, int level, bool attack_type_single);

    ~Basic_Tower() { }

    void attack();

private:
    bool _attack_type_single;
};

#endif