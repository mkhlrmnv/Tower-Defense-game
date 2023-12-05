#ifndef BASIC_TOWER_HPP
#define BASIC_TOWER_HPP

#include "tower.hpp"
#include "attack_types.hpp"
#include "level.hpp"

/**
 * @brief Test class for a Basic Tower
*/
class Basic_Tower : public Tower {
public:
    /**
     * @brief Constructor to initialize a Basic Tower object.
     * 
     * @param current_level Reference to the Level object.
     * @param position Initial position of the Basic Tower (Vector2D).
     * @param health Initial health points of the Basic Tower.
     * @param damage Damage inflicted by the Basic Tower.
     * @param range Range of attack for the Basic Tower.
     * @param attack_speed Speed of attack for the Basic Tower.
     * @param type Type of the Basic Tower.
     * @param price Price of the Basic Tower.
     * @param level Level of the Basic Tower.
     * @param attack_type_single Flag indicating single or multiple target attack type.
     */
    Basic_Tower(Level& current_level, Vector2D& position, int health = 30, int damage = 10, int range = 100,
                int attack_speed = 1, int type = ObjectTypes::ArcherTower, int price = 100, int level = 1, bool attack_type_single = true);

    /**
     * @brief Destructor for the Basic Tower.
     */
    ~Basic_Tower() { }

    /**
     * @brief Perform an attack action specific to the Basic Tower.
     * 
     * @return true if the attack is successful, false otherwise.
     */
    bool attack();

    /**
     * @brief Set the attack type to target multiple enemies.
     */
    void set_multiple_target();

private:
    bool _attack_type_single;
};

#endif
