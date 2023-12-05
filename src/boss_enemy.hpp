#ifndef BOSS_ENEMY_HPP
#define BOSS_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"

/**
 * @brief Class for a Boss enemy
*/
class Boss : public Enemy {
public:

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
