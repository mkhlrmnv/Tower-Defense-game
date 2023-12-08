#ifndef AOE_TOWER_HPP
#define AOE_TOWER_HPP

#include "tower.hpp"
#include "attack_types.hpp"
#include "level.hpp"

class Aoe_Tower: public Tower {
public:

    Aoe_Tower(Level& current_level, Vector2D& position, int health = 30, int damage = 10, int range = 100,
        int attack_speed = 2, int type = ObjectTypes::AoeTower, int price = 100, int level = 1);

    ~Aoe_Tower() { }

    bool attack();
};

#endif