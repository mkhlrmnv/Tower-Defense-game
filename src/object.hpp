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

enum State{none, walking_right, walking_left, attacking_right, attacking_left, dying};

class Object {
public:
    Object(Level& level, Vector2D& position, int health, int damage, int range, int attack_speed, int type);

    virtual ~Object();

    int get_damage() const;
    int get_health() const;
    int get_range() const;
    int get_attack_speed() const;
    const Vector2D get_position() const;
    int get_type() const;
    Level& get_level_reference() const;
    int get_attack_counter() const;

    void set_position(const Vector2D& position);
    void set_attack_counter(const int amount);

    void attack_counter_up();

    void gain_damage(int amount);
    void gain_health(int amount);
    void gain_range(int amount);
    void gain_attack_speed(int amount);

    double distance_to(const Vector2D& target_position);

    void lose_health(int amount);
    void lose_attack_speed(int amount);

    State get_state();

    void set_state(State state);

    virtual bool attack();

private:
    Level& _level;
    int _health_points;
    int _damage;
    int _range;
    int _attack_speed;
    int _attack_counter = 0;
    Vector2D _position;
    int _type;
    State _state;
};

#endif