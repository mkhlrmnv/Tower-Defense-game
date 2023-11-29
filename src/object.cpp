#include "object.hpp"
#include "level.hpp"

Object::Object(Level& level, Vector2D& position, int health, int damage, int range, int attack_speed, int type)
    : _level(level), _position(position), _health_points(health), _damage(damage), _range(range), _attack_speed(attack_speed), _type(type) {
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

Level& Object::get_level_reference() const {
    return _level;
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

State Object::get_state(){
    return _state;
}

void Object::set_state(State state){
    _state = state;
}

bool Object::attack() { return false;}