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
    /**
     * @brief Constructor to initialize a Repel Tower object.
     * 
     * @param current_level Reference to the Level object.
     * @param position Initial position of the Repel Tower (Vector2D).
     * @param health Initial health points of the Repel Tower.
     * @param damage Damage inflicted by the Repel Tower.
     * @param range Range of attack for the Repel Tower.
     * @param attack_speed Speed of attack for the Repel Tower.
     * @param type Type of the Repel Tower.
     * @param price Price of the Repel Tower.
     * @param level Level of the Repel Tower.
     */
    Repel_Tower(Level& current_level, Vector2D& position, int health = 350, int damage = 0, int range = 150,
                int attack_speed = 50, int type = ObjectTypes::RepelMageTower, int price = 250, int level = 1);

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
