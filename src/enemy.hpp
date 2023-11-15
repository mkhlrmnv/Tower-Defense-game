#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "object.hpp"

class Enemy: public Object {
public:
    Enemy(Level& level, int health, int damage, int range, int attack_speed, Vector2D position, int type, int speed, int defense) : 
            Object(level, health, damage, range, attack_speed, position, type), _speed(speed), _defense(defense) {}

    void move(Vector2D targetPosition) {
        set_position(targetPosition);
    }
    
private:
    int _speed;
    int _defense;
};

#endif