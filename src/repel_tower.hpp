#ifndef REPEL_TOWER_HPP
#define REPEL_TOWER_HPP

#include "tower.hpp"
#include "attack_types.hpp"
#include "level.hpp"

class Repel_Tower: public Tower {
public:

    Repel_Tower(Level& current_level, Vector2D& position, int health = 30, int damage = 5, int range = 120,
        int attack_speed = 1, int type = ObjectTypes::RepelMageTower, int price = 180, int level = 1);

    ~Repel_Tower() { }

    bool attack();
};

#endif