#ifndef FASTBOY_ENEMY_HPP
#define FASTBOY_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"
// #include "level.hpp"

class Basic_Enemy: public Enemy {
public:

    Basic_Enemy(Level& level, Vector2D& position, int health = 5, int damage = 0, int range = 0, int attack_speed = 1, 
        int type = ObjectTypes::FastBoy, int speed = 10, int defense = 5);

    ~Basic_Enemy() { }

    bool attack();

    // void move();
};

#endif