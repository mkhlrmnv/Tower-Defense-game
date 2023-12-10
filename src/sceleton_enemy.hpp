#ifndef SCELETON_ENEMY_HPP
#define SCELETON_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"

/**
 * @brief Class for Skeleton enemy
*/
class Sceleton : public Enemy {
/**
 * @brief Class for Skeleton enemy
*/
class Sceleton : public Enemy {
public:
    /**
     * @brief Constructor to initialize a Sceleton Enemy object.
     * 
     * @param level Reference to the Level object.
     * @param position Initial position of the Sceleton Enemy (Vector2D).
     * @param health Initial health points of the Sceleton Enemy.
     * @param damage Damage inflicted by the Sceleton Enemy.
     * @param range Range of attack for the Sceleton Enemy.
     * @param attack_speed Speed of attack for the Sceleton Enemy.
     * @param type Type of the Sceleton Enemy.
     * @param speed Speed attribute of the Sceleton Enemy.
     * @param defense Defense attribute of the Sceleton Enemy.
     * @param size Size of the Sceleton Enemy.
     */
    Sceleton(Level& level, Vector2D& position, int health = 100, int damage = 0,
             int range = 0, int attack_speed = 0, int type = ObjectTypes::NoobSkeleton_NoAttack,
             int speed = 3, int defense = 5, int size = 2);

    /**
     * @brief Destructor for the Sceleton Enemy.
     */
    ~Sceleton() { }

    /**
     * @brief Perform an attack action specific to the Sceleton Enemy.
     * 
     * @return true if the attack is successful, false otherwise.
     */
    bool attack();
};

#endif
