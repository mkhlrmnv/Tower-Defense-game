#include "level.hpp"

Level::Level(int resolution, std::string level, int cash, int lives):
    _square_size(resolution/10), _level_type(level), _round(0), _cash(cash), _lives(lives) { }

const int Level::get_Round() const {
    return _round;
}

const int Level::get_Cash() const {
    return _cash;
}

const int Level::get_Lives() const {
    return _lives;
}
