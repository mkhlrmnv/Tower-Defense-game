#ifndef TANK_ENEMY_HPP
#define TANK_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"

/**
 * @brief Class for a Tank enemy
*/
class Tank : public Enemy {
public:
    /**
     * @brief Constructor to initialize a Tank Enemy object.
     * 
     * @param level Reference to the Level object.
     * @param position Initial position of the Tank Enemy (Vector2D).
     * @param health Initial health points of the Tank Enemy.
     * @param damage Damage inflicted by the Tank Enemy.
     * @param range Range of attack for the Tank Enemy.
     * @param attack_speed Speed of attack for the Tank Enemy.
     * @param type Type of the Tank Enemy.
     * @param speed Speed attribute of the Tank Enemy.
     * @param defense Defense attribute of the Tank Enemy.
     * @param size Size of the Tank Enemy.
     */
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
