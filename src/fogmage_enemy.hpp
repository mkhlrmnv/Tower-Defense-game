#ifndef FOGMAGE_ENEMY_HPP
#define FOGMAGE_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"
// #include "level.hpp"

class Fog_Mage: public Enemy {
public:

    Fog_Mage(Level& level, Vector2D& position, int health = 50, int damage = 0, int range = 100, int attack_speed = 1, 
        int type = ObjectTypes::FogMage, int speed = 1, int defense = 5, int size = 3);

    ~Fog_Mage() { }

    bool attack();

    // void move();
};

#endif