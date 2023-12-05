#ifndef INFERNO_ENEMY_HPP
#define INFERNO_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"

/**
 * Class for an Inferno enemy
*/
class Inferno : public Enemy {
/**
 * Class for an Inferno enemy
*/
class Inferno : public Enemy {
public:
    /**
     * @brief Constructor to initialize an Inferno Enemy object.
     * 
     * @param level Reference to the Level object.
     * @param position Initial position of the Inferno Enemy (Vector2D).
     * @param health Initial health points of the Inferno Enemy.
     * @param damage Damage inflicted by the Inferno Enemy.
     * @param range Range of attack for the Inferno Enemy.
     * @param attack_speed Speed of attack for the Inferno Enemy.
     * @param type Type of the Inferno Enemy.
     * @param speed Speed attribute of the Inferno Enemy.
     * @param defense Defense attribute of the Inferno Enemy.
     * @param size Size of the Inferno Enemy.
     */
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
