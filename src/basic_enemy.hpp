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
    /**
     * @brief Constructor to initialize a Basic Enemy object.
     * 
     * @param level Reference to the Level object.
     * @param position Initial position of the Basic Enemy (Vector2D).
     * @param health Initial health points of the Basic Enemy.
     * @param damage Damage inflicted by the Basic Enemy.
     * @param range Range of attack for the Basic Enemy.
     * @param attack_speed Speed of attack for the Basic Enemy.
     * @param type Type of the Basic Enemy.
     * @param speed Speed attribute of the Basic Enemy.
     * @param defense Defense attribute of the Basic Enemy.
     * @param size Size of the Basic Enemy.
     */
    Basic_Enemy(Level& level, Vector2D& position, int health = 20, int damage = 5, int range = 100, int attack_speed = 1,
                int type = ObjectTypes::NoobDemon_CanAttack, int speed = 20, int defense = 5, int size = 3);

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
