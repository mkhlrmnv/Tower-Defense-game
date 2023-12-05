#ifndef HEALER_ENEMY_HPP
#define HEALER_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"
// #include "level.hpp"

class Healer: public Enemy {
public:

    Healer(Level& level, Vector2D& position, int health = 30, int damage = 0, int range = 60, int attack_speed = 2, 
        int type = ObjectTypes::HealerPriest, int speed = 1, int defense = 5, int size = 2);

    ~Healer() { }

    bool attack();

    // void move();
};

#endif