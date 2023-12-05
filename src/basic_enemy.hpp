#ifndef BASIC_ENEMY_HPP
#define BASIC_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"
// #include "level.hpp"

/**
 * @brief Test class for Basic enemy
*/
class Basic_Enemy : public Enemy {
public:

    Basic_Enemy(Level& level, Vector2D& position, int health = 20, int damage = 5, int range = 100, int attack_speed = 1, int type = ObjectTypes::NoobDemon_CanAttack, int speed = 20, int defense = 5, int size = 3);

    /**
     * @brief Destructor for the Basic Enemy.
     */
    ~Basic_Enemy() { }

    /**
     * @brief Perform an attack action specific to the Basic Enemy.
     * 
     * @return true if the attack is successful, false otherwise.
     */
    bool attack();
};

#endif
