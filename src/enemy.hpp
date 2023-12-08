#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "object.hpp"

class Enemy: public Object {
public:
    Enemy(Level& level, Vector2D& position, int health, int damage, int range, int attack_speed, int type, int speed, int defense);

    ~Enemy() { }

    int get_speed() const;
    int get_original_speed() const;

    int get_defense() const;

    void lose_speed(int amount);
    void set_speed(int amount);

    void move();

    // void State get_state();

    // bool attack();

    std::vector<Vector2D> get_route() const;

    void set_route_position(Vector2D position);

    Vector2D get_prev_pos();

    void set_prev_pos(Vector2D pos);

private:
    Vector2D _prev_pos;
    int _speed;
    int _original_speed = 0;
    int _defense;
    std::vector<Vector2D> _route;
};

#endif