#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "object.hpp"

class Enemy: public Object {
public:
    Enemy(Level& level, int health, int damage, int range, int attack_speed, Vector2D position, int type, int speed, int defense);

    ~Enemy() { }

    int get_speed() const;

    int get_defense() const;

    void move();

    // void attack();

    std::vector<Vector2D> get_route() const;

    void set_route_position(Vector2D position);

    Vector2D get_prev_pos();

    void set_prev_pos(Vector2D pos);

private:
    Vector2D _prev_pos;
    int _speed;
    int _defense;
    std::vector<Vector2D> _route;
};

#endif