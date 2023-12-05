#ifndef DEMON_ENEMY_HPP
#define DEMON_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"
// #include "level.hpp"

class Demon: public Enemy {
public:

    Demon(Level& level, Vector2D& position, int health = 10, int damage = 5, int range = 100, int attack_speed = 1, 
        int type = ObjectTypes::NoobDemon_CanAttack, int speed = 2, int defense = 5, int size = 3);

    ~Demon() { }

    bool attack();

    // void move();
};

#endif