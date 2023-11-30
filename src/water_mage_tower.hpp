#ifndef WATER_MAGE_TOWER_HPP
#define WATER_MAGE_TOWER_HPP

#include "tower.hpp"
#include "attack_types.hpp"
#include "level.hpp"

class Water_Mage_Tower: public Tower {
public:

    Water_Mage_Tower(Level& current_level, Vector2D& position, int health = 40, int damage = 40, int range = 80,
        int attack_speed = 2, int type = ObjectTypes::WaterMageTower, int price = 250, int level = 1);

    ~Water_Mage_Tower() { }

    bool attack();
};

#endif