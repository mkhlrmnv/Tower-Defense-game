#ifndef ARCHER_TOWER_HPP
#define ARCHER_TOWER_HPP

#include "tower.hpp"
#include "attack_types.hpp"
#include "level.hpp"

/**
 * @brief Class for Archer tower
*/
class Archer_Tower : public Tower {
/**
 * @brief Class for Archer tower
*/
class Archer_Tower : public Tower {
public:
    /**
     * @brief Constructor to initialize an Archer Tower object.
     * 
     * @param current_level Reference to the Level object.
     * @param position Initial position of the Archer Tower (Vector2D).
     * @param health Initial health points of the Archer Tower.
     * @param damage Damage inflicted by the Archer Tower.
     * @param range Range of attack for the Archer Tower.
     * @param attack_speed Speed of attack for the Archer Tower.
     * @param type Type of the Archer Tower.
     * @param price Price of the Archer Tower.
     * @param level Level of the Archer Tower.
     */
    Archer_Tower(Level& current_level, Vector2D& position, int health = 100, int damage = 10, int range = 250,
                 int attack_speed = 15, int type = ObjectTypes::ArcherTower, int price = 100, int level = 1);

    /**
     * @brief Destructor for the Archer Tower.
     */
    ~Archer_Tower() { }

    /**
     * @brief Perform an attack action specific to the Archer Tower.
     * 
     * @return true if the attack is successful, false otherwise.
     */
    bool attack();
};

#endif
