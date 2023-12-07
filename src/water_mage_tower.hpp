#ifndef WATER_MAGE_TOWER_HPP
#define WATER_MAGE_TOWER_HPP

#include "tower.hpp"
#include "attack_types.hpp"
#include "level.hpp"

/**
 * @brief Class for a Water Mage tower
*/
class Water_Mage_Tower: public Tower {
public:
    /**
     * @brief Constructor to initialize a Water Mage Tower object.
     * 
     * @param current_level Reference to the Level object.
     * @param position Initial position of the Water Mage Tower (Vector2D).
     * @param health Initial health points of the Water Mage Tower.
     * @param damage Damage inflicted by the Water Mage Tower.
     * @param range Range of attack for the Water Mage Tower.
     * @param attack_speed Speed of attack for the Water Mage Tower.
     * @param type Type of the Water Mage Tower.
     * @param price Price of the Water Mage Tower.
     * @param level Level of the Water Mage Tower.
     */
    Water_Mage_Tower(Level& current_level, Vector2D& position, int health = 300, int damage = 40, int range = 150,
                     int attack_speed = 25, int type = ObjectTypes::WaterMageTower, int price = 250, int level = 1);

    /**
     * @brief Destructor for the Water Mage Tower.
     */
    ~Water_Mage_Tower() { }

    /**
     * @brief Perform an attack action specific to the Water Mage Tower.
     * 
     * @return true if the attack is successful, false otherwise.
     */
    bool attack();
};

#endif