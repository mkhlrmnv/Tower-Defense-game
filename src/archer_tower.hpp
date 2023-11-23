#ifndef ARCHER_TOWER_HPP
#define ARCHER_TOWER_HPP

#include "tower.hpp"
#include "attack_types.hpp"
#include "level.hpp"

class Archer_Tower: public Tower {
public:

    Archer_Tower(Level& current_level, Vector2D& position, int health = 30, int damage = 10, int range = 100,
        int attack_speed = 3, int type = ObjectTypes::ArcherTower, int price = 100, int level = 1);

    ~Archer_Tower() { }

    bool attack();
};

#endif