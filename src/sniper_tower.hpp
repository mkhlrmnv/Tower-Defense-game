#ifndef SNIPER_TOWER_HPP
#define SNIPER_TOWER_HPP

#include "tower.hpp"
#include "attack_types.hpp"
#include "level.hpp"

/**
 * @brief Class for Sniper tower
*/
class Sniper_Tower : public Tower {
/**
 * @brief Class for Sniper tower
*/
class Sniper_Tower : public Tower {
public:
    /**
     * @brief Constructor to initialize a Sniper Tower object.
     * 
     * @param current_level Reference to the Level object.
     * @param position Initial position of the Sniper Tower (Vector2D).
     * @param health Initial health points of the Sniper Tower.
     * @param damage Damage inflicted by the Sniper Tower.
     * @param range Range of attack for the Sniper Tower.
     * @param attack_speed Speed of attack for the Sniper Tower.
     * @param type Type of the Sniper Tower.
     * @param price Price of the Sniper Tower.
     * @param level Level of the Sniper Tower.
     */
    Sniper_Tower(Level& current_level, Vector2D& position, int health = 200, int damage = 120, int range = 999,
                 int attack_speed = 120, int type = ObjectTypes::SniperTower, int price = 200, int level = 1);

    /**
     * @brief Destructor for the Sniper Tower.
     */
    ~Sniper_Tower() { }

    /**
     * @brief Perform an attack action specific to the Sniper Tower.
     * 
     * @return true if the attack is successful, false otherwise.
     */
    bool attack();
};

#endif
