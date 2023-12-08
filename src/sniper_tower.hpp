#ifndef SNIPER_TOWER_HPP
#define SNIPER_TOWER_HPP

#include "tower.hpp"
#include "attack_types.hpp"
#include "level.hpp"

class Sniper_Tower: public Tower {
public:

    Sniper_Tower(Level& current_level, Vector2D& position, int health = 10, int damage = 30, int range = 1000,
        int attack_speed = 1, int type = ObjectTypes::SniperTower, int price = 150, int level = 1);

    ~Sniper_Tower() { }

    bool attack();
};

#endif