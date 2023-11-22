#ifndef BASIC_TOWER_HPP
#define BASIC_TOWER_HPP

#include "tower.hpp"
#include "attack_types.hpp"
#include "level.hpp"

class Basic_Tower: public Tower {
public:

    Basic_Tower(Level& current_level, Vector2D& position, int health = 30, int damage = 10, int range = 100,
        int attack_speed = 1, int type = BASIC, int price = 100, int level = 1, bool attack_type_single = true);

    ~Basic_Tower() { }

    bool attack();

    void set_multiple_target();

private:
    bool _attack_type_single;
};

#endif