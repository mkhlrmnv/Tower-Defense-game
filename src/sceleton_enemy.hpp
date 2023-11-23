#ifndef SCELETON_ENEMY_HPP
#define SCELETON_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"
// #include "level.hpp"

class Basic_Enemy: public Enemy {
public:

    Basic_Enemy(Level& level, Vector2D& position, int health = 20, int damage = 0, 
        int range = 0, int attack_speed = 0, int type = ObjectTypes::NoobSkeleton_NoAttack, 
        int speed = 3, int defense = 5);

    ~Basic_Enemy() { }

    bool attack();
};

#endif