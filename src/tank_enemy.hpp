#ifndef TANK_ENEMY_HPP
#define TANK_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"
// #include "level.hpp"

class Basic_Enemy: public Enemy {
public:

    Basic_Enemy(Level& level, Vector2D& position, int health = 100, int damage = 5, int range = 80, int attack_speed = 1, 
        int type = ObjectTypes::TankOrc, int speed = 1, int defense = 100);

    ~Basic_Enemy() { }

    bool attack();

    // void move();
};

#endif