#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "vector2d.hpp"

class Object {
public:
    Object(int health, int damage, 
            int range, int attack_speed, Vector2D& position);

    ~Object();

    const int get_damage() const;
    const int get_health() const;
    const int get_range() const;
    const int get_attack_speed() const;
    Vector2D get_position() const;

    void set_position(const Vector2D& position);

    void lose_health(int amount);

    virtual void attack();

private:
    int _health_points;
    int _damage;
    int _range;
    int _attack_speed;
    Vector2D _position;
};

#endif