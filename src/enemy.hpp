#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "object.hpp"

class Enemy: public Object {
public:
    Enemy(Level& level, int health, int damage, int range, int attack_speed, Vector2D position, int type, int speed, int defense) : 
            Object(level, health, damage, range, attack_speed, position, type), _speed(speed), _defense(defense) {}

    int get_speed() const {
        return _speed;
    }

    int get_defense() const {
        return _defense;
    }

    virtual void move() {}

    std::vector<Vector2D> get_route() const {
        return _route;
    }
    
    void set_route_position(Vector2D position) {
        _route.push_back(position);
    }

private:
    int _speed;
    int _defense;
    std::vector<Vector2D> _route;
};

#endif