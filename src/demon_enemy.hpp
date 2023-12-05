#ifndef DEMON_ENEMY_HPP
#define DEMON_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"

/**
 * Class for a Demon enemy
*/
class Demon : public Enemy {
public:

    Demon(Level& level, Vector2D& position, int health = 80, int damage = 5, int range = 100, int attack_speed = 1, 
        int type = ObjectTypes::NoobDemon_CanAttack, int speed = 2, int defense = 5, int size = 3);

    /**
     * @brief Destructor for the Demon Enemy.
     */
    ~Demon() { }

    /**
     * @brief Perform an attack action specific to the Demon Enemy.
     * 
     * @return true if the attack is successful, false otherwise.
     */
    bool attack();
};

#endif
