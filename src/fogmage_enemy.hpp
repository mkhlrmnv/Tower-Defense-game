#ifndef FOGMAGE_ENEMY_HPP
#define FOGMAGE_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"

/**
 * @brief Class for a Fog Mage enemy
*/
class Fog_Mage : public Enemy {
public:

    Fog_Mage(Level& level, Vector2D& position, int health = 50, int damage = 0, int range = 100, int attack_speed = 1, 
        int type = ObjectTypes::FogMage, int speed = 1, int defense = 5, int size = 3);

    /**
     * @brief Destructor for the Fog Mage Enemy.
     */
    ~Fog_Mage() { }

    /**
     * @brief Perform an attack action specific to the Fog Mage Enemy.
     * 
     * @return true if the attack is successful, false otherwise.
     */
    bool attack();
};

#endif
