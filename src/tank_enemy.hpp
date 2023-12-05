#ifndef TANK_ENEMY_HPP
#define TANK_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"

/**
 * @brief Class for a Tank enemy
*/
class Tank : public Enemy {
public:

    Tank(Level& level, Vector2D& position, int health = 300, int damage = 5, int range = 80, int attack_speed = 1, 
        int type = ObjectTypes::TankOrc, int speed = 1, int defense = 100, int size = 4);

    /**
     * @brief Destructor for the Tank Enemy.
     */
    ~Tank() { }

    /**
     * @brief Perform an attack action specific to the Tank Enemy.
     * 
     * @return true if the attack is successful, false otherwise.
     */
    bool attack();
};

#endif
