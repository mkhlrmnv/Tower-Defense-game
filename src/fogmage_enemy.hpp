#ifndef FOGMAGE_ENEMY_HPP
#define FOGMAGE_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"

/**
 * @brief Class for a Fog Mage enemy
*/
class Fog_Mage : public Enemy {
/**
 * @brief Class for a Fog Mage enemy
*/
class Fog_Mage : public Enemy {
public:
    /**
     * @brief Constructor to initialize a Fog Mage Enemy object.
     * 
     * @param level Reference to the Level object.
     * @param position Initial position of the Fog Mage Enemy (Vector2D).
     * @param health Initial health points of the Fog Mage Enemy.
     * @param damage Damage inflicted by the Fog Mage Enemy.
     * @param range Range of attack for the Fog Mage Enemy.
     * @param attack_speed Speed of attack for the Fog Mage Enemy.
     * @param type Type of the Fog Mage Enemy.
     * @param speed Speed attribute of the Fog Mage Enemy.
     * @param defense Defense attribute of the Fog Mage Enemy.
     * @param size Size of the Fog Mage Enemy.
     */
    Fog_Mage(Level& level, Vector2D& position, int health = 300, int damage = 0, int range = 150, int attack_speed = 50,
             int type = ObjectTypes::FogMage, int speed = 1, int defense = 10, int size = 4);

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
