#ifndef FASTBOY_ENEMY_HPP
#define FASTBOY_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"
// #include "level.hpp"

class Fast_Boy: public Enemy {
public:

    Fast_Boy(Level& level, Vector2D& position, int health = 20, int damage = 0, int range = 0, int attack_speed = 1, 
        int type = ObjectTypes::FastBoy, int speed = 10, int defense = 5, int size = 1);

    ~Fast_Boy() { }

    bool attack();

    // void move();
};

#endif