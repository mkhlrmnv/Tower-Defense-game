#ifndef SCELETON_ENEMY_HPP
#define SCELETON_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"
// #include "level.hpp"

class Sceleton: public Enemy {
public:

    Sceleton(Level& level, Vector2D& position, int health = 60, int damage = 0, 
        int range = 0, int attack_speed = 0, int type = ObjectTypes::NoobSkeleton_NoAttack, 
        int speed = 3, int defense = 5, int size = 2);

    ~Sceleton() { }

    bool attack();
};

#endif