#ifndef FOGMAGE_ENEMY_HPP
#define FOGMAGE_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"
// #include "level.hpp"

class Basic_Enemy: public Enemy {
public:

    Basic_Enemy(Level& level, Vector2D& position, int health = 20, int damage = 0, int range = 40, int attack_speed = 1, 
        int type = ObjectTypes::FogMage, int speed = 1, int defense = 5);

    ~Basic_Enemy() { }

    bool attack();

    // void move();
};

#endif