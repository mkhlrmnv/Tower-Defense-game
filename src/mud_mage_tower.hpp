#ifndef MUD_MAGE_TOWER_HPP
#define MUD_MAGE_TOWER_HPP

#include "tower.hpp"
#include "attack_types.hpp"
#include "level.hpp"

class Mud_Mage_Tower: public Tower {
public:

    Mud_Mage_Tower(Level& current_level, Vector2D& position, int health = 20, int damage = 15, int range = 100,
        int attack_speed = 3, int type = ObjectTypes::MudMageTower, int price = 140, int level = 1);

    ~Mud_Mage_Tower() { }

    bool attack();
};

#endif