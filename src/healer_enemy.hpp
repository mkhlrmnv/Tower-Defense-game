#ifndef HEALER_ENEMY_HPP
#define HEALER_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"

/**
 * Class for a Healer enemy
*/
class Healer : public Enemy {
public:

    Healer(Level& level, Vector2D& position, int health = 40, int damage = 0, int range = 60, int attack_speed = 2, 
        int type = ObjectTypes::HealerPriest, int speed = 1, int defense = 5, int size = 2);

    /**
     * @brief Destructor for the Healer Enemy.
     */
    ~Healer() { }

    /**
     * @brief Perform an attack action specific to the Healer Enemy.
     * 
     * @return true if the attack is successful, false otherwise.
     */
    bool attack();
};

#endif
