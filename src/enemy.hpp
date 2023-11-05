#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "object.hpp"

class Enemy: public Object {
public:
    Enemy(int health, int damage, int range, int attack_speed, Vector2D& position, int speed, int defense);

    void move(Vector2D targetPosition);

private:
    int _speed;
    int _defense;
};

#endif