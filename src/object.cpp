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

int Object::get_original_attack_speed() const {
    return (_original_attack_speed == 0) ? _attack_speed : _original_attack_speed;
}

int Object::get_original_attack_speed() const {
    return (_original_attack_speed == 0) ? _attack_speed : _original_attack_speed;
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

int Object::get_attack_counter() const {
    return _attack_counter;
}

int Object::get_reset_counter() const {
    return _reset_counter;
}

int Object::get_wait_time() const {
    return _reset_wait_time;
}

void Object::set_attack_counter(const int amount) {
    _attack_counter = amount;
}

void Object::set_reset_counter(const int amount) {
    _reset_counter = amount;
}

void Object::attack_counter_up() {
    _attack_counter -= 1;
}

void Object::reset_counter_up() {
    _reset_counter += 1;
}

void Object::set_position(const Vector2D& position) {
    _position = position;
}

void Object::set_attack_speed(const int amount) {
    _attack_speed = amount;
}

void Object::set_original_attack_speed(const int amount) {
    _original_attack_speed = amount;
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
    if (_original_attack_speed == 0) {
        _original_attack_speed = _attack_speed;
    }

    if (_attack_speed - amount > 0) {
        _attack_speed -= amount;
    }
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

void Object::lose_attack_speed(int amount) {
    if (_original_attack_speed == 0) {
        _original_attack_speed = _attack_speed;
<<<<<<< HEAD
=======
    }

    if (_attack_speed == _original_attack_speed) {
        _attack_speed += amount;
    }
}

State Object::get_state(){
    return _state;
}

void Object::set_state(State state){
    _state = state;
}

bool Object::attack() { return false;}