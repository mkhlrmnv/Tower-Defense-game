#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "vector2d.hpp"

#include <vector>
#include <math.h>
#include <algorithm>
#include <stdexcept>
#include <chrono>
#include <thread>

class Level;

class Object {
public:
    Object(Level& level, int health, int damage, int range, int attack_speed, Vector2D& position, int type);

    virtual ~Object();

    int get_damage() const;
    int get_health() const;
    int get_range() const;
    int get_attack_speed() const;
    const Vector2D get_position() const;
    int get_type() const;

    void set_position(const Vector2D& position);

    void gain_damage(int amount);
    void gain_health(int amount);
    void gain_range(int amount);
    void gain_attack_speed(int amount);

    double distance_to(const Vector2D& target_position);

    void lose_health(int amount);

    virtual void attack();

private:
    Level& _level;
    int _health_points;
    int _damage;
    int _range;
    int _attack_speed;
    Vector2D _position;
    int _type;
};

#endif