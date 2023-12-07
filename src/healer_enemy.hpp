#ifndef HEALER_ENEMY_HPP
#define HEALER_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"

/**
 * Class for a Healer enemy
*/
class Healer : public Enemy {
/**
 * Class for a Healer enemy
*/
class Healer : public Enemy {
public:
    /**
     * @brief Constructor to initialize a Healer Enemy object.
     * 
     * @param level Reference to the Level object.
     * @param position Initial position of the Healer Enemy (Vector2D).
     * @param health Initial health points of the Healer Enemy.
     * @param damage Damage inflicted by the Healer Enemy.
     * @param range Range of attack for the Healer Enemy.
     * @param attack_speed Speed of attack for the Healer Enemy.
     * @param type Type of the Healer Enemy.
     * @param speed Speed attribute of the Healer Enemy.
     * @param defense Defense attribute of the Healer Enemy.
     * @param size Size of the Healer Enemy.
     */
    Healer(Level& level, Vector2D& position, int health = 200, int damage = 0, int range = 100, int attack_speed = 20,
           int type = ObjectTypes::HealerPriest, int speed = 1, int defense = 10, int size = 2);

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
