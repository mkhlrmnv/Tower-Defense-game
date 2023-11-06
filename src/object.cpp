#include "object.hpp"
#include "attack_types.hpp"

#include <math.h>
#include <algorithm>
#include <stdexcept>

Object::Object(int health, int damage, int range, int attack_speed, Vector2D& position, int type)
    : _health_points(health), _damage(damage), _range(range), _attack_speed(attack_speed), _position(position), _type(type) {
}

Object::~Object() {}

int Object::get_damage() const {
    return _damage;
}

int Object::get_health() const {
    return _health_points;
}

int Object::get_range() const {
    return _range;
}

int Object::get_attack_speed() const {
    return _attack_speed;
}

const Vector2D Object::get_position() const {
    return _position;
}

int Object::get_type() const {
    return _type;
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

double Object::distance_to(const Vector2D& target_position) {
    return sqrt(pow(target_position.x - this->get_position().x, 2) + pow(target_position.y - this->get_position().y, 2));
}

void Object::lose_health(int amount) {
    if (amount > 0) {
        _health_points -= amount;
        if (_health_points < 0) {
            _health_points = 0;
        }
    }
}

void Object::attack() {}

std::vector<std::pair<double, Object*>> Object::distances(bool enemies) {
    std::vector<std::pair<double, Object*>> distances;

    if (!enemies) {
        std::vector<Enemy*> enemyList = _current_level->get_enemies();
        for (Enemy* obj : enemyList) {
            double dist = this->distance_to(obj->get_position());
            distances.push_back(std::make_pair(dist, obj));
        }
    } else {
        std::vector<Tower*> towerList = _current_level->get_towers();
        for (Tower* obj : towerList) {
            double dist = this->distance_to(obj->get_position());
            distances.push_back(std::make_pair(dist, obj));
        }
    }

    // Sort the objects by distance in ascending order
    std::sort(distances.begin(), distances.end(), [](const std::pair<double, Object*> a, const std::pair<double, Object*> b) {
        return a.first < b.first;
    });

    return distances;
}