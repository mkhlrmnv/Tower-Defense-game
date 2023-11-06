#ifndef BASIC_ENEMY_HPP
#define BASIC_ENEMY_HPP

#include "enemy.hpp"

class Basic_Enemy: public Enemy {
public:
    Basic_Enemy();

    Basic_Enemy(int health, int damage, int range, int attack_speed, Vector2D& position, int type, int speed, int defense);

    void attack();
};

#endif