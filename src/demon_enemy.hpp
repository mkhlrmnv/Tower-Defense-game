#ifndef DEMON_ENEMY_HPP
#define DEMON_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"

/**
 * Class for a Demon enemy
*/
class Demon : public Enemy {
public:
    /**
     * @brief Constructor to initialize a Demon Enemy object.
     * 
     * @param level Reference to the Level object.
     * @param position Initial position of the Demon Enemy (Vector2D).
     * @param health Initial health points of the Demon Enemy.
     * @param damage Damage inflicted by the Demon Enemy.
     * @param range Range of attack for the Demon Enemy.
     * @param attack_speed Speed of attack for the Demon Enemy.
     * @param type Type of the Demon Enemy.
     * @param speed Speed attribute of the Demon Enemy.
     * @param defense Defense attribute of the Demon Enemy.
     * @param size Size of the Demon Enemy.
     */
    Demon(Level& level, Vector2D& position, int health = 200, int damage = 10, int range = 130, int attack_speed = 20,
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
