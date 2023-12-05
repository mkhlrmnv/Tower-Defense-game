#ifndef BOSS_ENEMY_HPP
#define BOSS_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"

/**
 * @brief Class for a Boss enemy
*/
class Boss : public Enemy {
public:
    /**
     * @brief Constructor to initialize a Boss Enemy object.
     * 
     * @param level Reference to the Level object.
     * @param position Initial position of the Boss Enemy (Vector2D).
     * @param health Initial health points of the Boss Enemy.
     * @param damage Damage inflicted by the Boss Enemy.
     * @param range Range of attack for the Boss Enemy.
     * @param attack_speed Speed of attack for the Boss Enemy.
     * @param type Type of the Boss Enemy.
     * @param speed Speed attribute of the Boss Enemy.
     * @param defense Defense attribute of the Boss Enemy.
     * @param size Size of the Boss Enemy.
     */
    Boss(Level& level, Vector2D& position, int health = 100, int damage = 10, int range = 80, int attack_speed = 1, 
         int type = ObjectTypes::BossKnight, int speed = 1, int defense = 20, int size = 5);

    /**
     * @brief Destructor for the Boss Enemy.
     */
    ~Boss() { }

    /**
     * @brief Perform an attack action specific to the Boss Enemy.
     * 
     * @return true if the attack is successful, false otherwise.
     */
    bool attack();
};

#endif
