#ifndef AOE_TOWER_HPP
#define AOE_TOWER_HPP

#include "tower.hpp"
#include "attack_types.hpp"
#include "level.hpp"

/**
 * @brief Class for AOE tower
*/
class Aoe_Tower : public Tower {
/**
 * @brief Class for AOE tower
*/
class Aoe_Tower : public Tower {
public:
    /**
     * @brief Constructor to initialize an AOE Tower object.
     * 
     * @param current_level Reference to the Level object.
     * @param position Initial position of the AOE Tower (Vector2D).
     * @param health Initial health points of the AOE Tower.
     * @param damage Damage inflicted by the AOE Tower.
     * @param range Range of attack for the AOE Tower.
     * @param attack_speed Speed of attack for the AOE Tower.
     * @param type Type of the AOE Tower.
     * @param price Price of the AOE Tower.
     * @param level Level of the AOE Tower.
     */
    Aoe_Tower(Level& current_level, Vector2D& position, int health = 80, int damage = 2, int range = 250,
              int attack_speed = 10, int type = ObjectTypes::AoeTower, int price = 100, int level = 1);

    /**
     * @brief Destructor for the AOE Tower.
     */
    ~Aoe_Tower() { }

    /**
     * @brief Perform an attack action specific to the AOE Tower.
     * 
     * @return true if the attack is successful, false otherwise.
     */
    bool attack();
};

#endif
