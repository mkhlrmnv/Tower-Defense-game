#ifndef BASIC_ENEMY_HPP
#define BASIC_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"
// #include "level.hpp"

class Basic_Enemy: public Enemy {
public:

    Basic_Enemy(Level& level, Vector2D& position, int health = 20, int damage = 5, int range = 100, int attack_speed = 1, int type = ObjectTypes::NoobDemon_CanAttack, int speed = 20, int defense = 5, int size = 3);

    ~Basic_Enemy() { }

    bool attack();

    // void move();
};

#endif