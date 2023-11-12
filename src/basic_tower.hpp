#ifndef BASIC_TOWER_HPP
#define BASIC_TOWER_HPP

#include "tower.hpp"
#include "attack_types.hpp"

#include <chrono>
#include <thread>

class Basic_Tower: public Tower {
public:
    // Basic_Tower();

    Basic_Tower(int health, int damage, int range, int attack_speed, Vector2D& position, int type, int price, int level, bool attack_type_single);

    void attack();

private:
    bool _attack_type_single;
};

#endif