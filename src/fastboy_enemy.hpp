#ifndef FASTBOY_ENEMY_HPP
#define FASTBOY_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"

/**
 * Class for a Fast boy enemy
*/
class Fast_Boy : public Enemy {
public:
    /**
     * @brief Constructor to initialize a Fast Boy Enemy object.
     * 
     * @param level Reference to the Level object.
     * @param position Initial position of the Fast Boy Enemy (Vector2D).
     * @param health Initial health points of the Fast Boy Enemy.
     * @param damage Damage inflicted by the Fast Boy Enemy.
     * @param range Range of attack for the Fast Boy Enemy.
     * @param attack_speed Speed of attack for the Fast Boy Enemy.
     * @param type Type of the Fast Boy Enemy.
     * @param speed Speed attribute of the Fast Boy Enemy.
     * @param defense Defense attribute of the Fast Boy Enemy.
     * @param size Size of the Fast Boy Enemy.
     */
    Fast_Boy(Level& level, Vector2D& position, int health = 50, int damage = 0, int range = 0, int attack_speed = 1,
             int type = ObjectTypes::FastBoy, int speed = 5, int defense = 5, int size = 1);

    /**
     * @brief Destructor for the Fast Boy Enemy.
     */
    ~Fast_Boy() { }

    /**
     * @brief Perform an attack action specific to the Fast Boy Enemy.
     * 
     * @return true if the attack is successful, false otherwise.
     */
    bool attack();
};

#endif
