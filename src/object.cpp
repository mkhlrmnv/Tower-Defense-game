#include "object.hpp"

Object::Object(int health, int damage, int range, int attack_speed, Vector2D& position)
    : _health_points(health), _damage(damage), _range(range), _attack_speed(attack_speed), _position(position) {
}

Object::~Object() {}

const int Object::get_damage() const {
    return _damage;
}

const int Object::get_health() const {
    return _health_points;
}

const int Object::get_range() const {
    return _range;
}

const int Object::get_attack_speed() const {
    return _attack_speed;
}

Vector2D Object::get_position() const {
    return _position;
}

void Object::set_position(const Vector2D& position) {
    _position = position;
}

void Object::gain_damage(int amount) {
    _damage += amount;
}

void Object::gain_health(int amount) {
    _health_points += amount;
}

void Object::gain_range(int amount) {
    _range += amount;
}

void Object::gain_attack_speed(int amount) {
    _attack_speed += amount;
}

void Object::lose_health(int amount) {
    if (amount > 0) {
        _health_points -= amount;
        if (_health_points < 0) {
            _health_points = 0;
        }
    }
}

void Object::attack(Object target) {
    target.lose_health(_damage);
}