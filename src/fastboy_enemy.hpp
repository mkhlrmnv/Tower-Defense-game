#ifndef FASTBOY_ENEMY_HPP
#define FASTBOY_ENEMY_HPP

#include "enemy.hpp"
#include "attack_types.hpp"

/**
 * Class for a Fast boy enemy
*/
class Fast_Boy : public Enemy {
public:

    Fast_Boy(Level& level, Vector2D& position, int health = 20, int damage = 0, int range = 0, int attack_speed = 1, 
        int type = ObjectTypes::FastBoy, int speed = 10, int defense = 5, int size = 1);

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
