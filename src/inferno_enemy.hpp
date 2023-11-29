#ifndef INFERNO_ENEMY_HPP
#define INFERNO_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"
// #include "level.hpp"

class Inferno: public Enemy {
public:

    Inferno(Level& level, Vector2D& position, int health = 20, int damage = 5, int range = 100, int attack_speed = 1, 
        int type = ObjectTypes::InfernoMage, int speed = 3, int defense = 10);

    ~Inferno() { }

    bool attack();

    // void move();
};

#endif