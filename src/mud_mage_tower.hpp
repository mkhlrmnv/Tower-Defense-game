#ifndef MUD_MAGE_TOWER_HPP
#define MUD_MAGE_TOWER_HPP

#include "tower.hpp"
#include "attack_types.hpp"
#include "level.hpp"

/**
 * @brief Class for a Mud Mage tower
*/
class Mud_Mage_Tower : public Tower {
/**
 * @brief Class for a Mud Mage tower
*/
class Mud_Mage_Tower : public Tower {
public:
    /**
     * @brief Constructor to initialize a Mud Mage Tower object.
     * 
     * @param current_level Reference to the Level object.
     * @param position Initial position of the Mud Mage Tower (Vector2D).
     * @param health Initial health points of the Mud Mage Tower.
     * @param damage Damage inflicted by the Mud Mage Tower.
     * @param range Range of attack for the Mud Mage Tower.
     * @param attack_speed Speed of attack for the Mud Mage Tower.
     * @param type Type of the Mud Mage Tower.
     * @param price Price of the Mud Mage Tower.
     * @param level Level of the Mud Mage Tower.
     */
    Mud_Mage_Tower(Level& current_level, Vector2D& position, int health = 20, int damage = 15, int range = 100,
                   int attack_speed = 3, int type = ObjectTypes::MudMageTower, int price = 140, int level = 1);

    /**
     * @brief Destructor for the Mud Mage Tower.
     */
    ~Mud_Mage_Tower() { }

    /**
     * @brief Perform an attack action specific to the Mud Mage Tower.
     * 
     * @return true if the attack is successful, false otherwise.
     */
    bool attack();
};

#endif
