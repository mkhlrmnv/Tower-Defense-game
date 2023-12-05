#ifndef INFERNO_ENEMY_HPP
#define INFERNO_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"

/**
 * Class for an Inferno enemy
*/
class Inferno : public Enemy {
public:

    Inferno(Level& level, Vector2D& position, int health = 70, int damage = 5, int range = 100, int attack_speed = 1, 
        int type = ObjectTypes::InfernoMage, int speed = 3, int defense = 10, int size = 3);

    /**
     * @brief Destructor for the Inferno Enemy.
     */
    ~Inferno() { }

    /**
     * @brief Perform an attack action specific to the Inferno Enemy.
     * 
     * @return true if the attack is successful, false otherwise.
     */
    bool attack();
};

#endif
