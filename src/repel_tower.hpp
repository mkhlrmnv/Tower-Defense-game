#ifndef REPEL_TOWER_HPP
#define REPEL_TOWER_HPP

#include "tower.hpp"
#include "attack_types.hpp"
#include "level.hpp"

/**
 * @brief Class for a Repel tower
*/
class Repel_Tower : public Tower {
public:

    Repel_Tower(Level& current_level, Vector2D& position, int health = 30, int damage = 0, int range = 120,
        int attack_speed = 5, int type = ObjectTypes::RepelMageTower, int price = 180, int level = 1);

    /**
     * @brief Destructor for the Repel Tower.
     */
    ~Repel_Tower() { }

    /**
     * @brief Perform an attack action specific to the Repel Tower.
     * 
     * @return true if the attack is successful, false otherwise.
     */
    bool attack();
};

#endif
