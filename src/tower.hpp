#ifndef TOWER_HPP
#define TOWER_HPP

#include "object.hpp"

/**
 * @brief Tower class for handling all towers
*/
class Tower : public Object {
public:
    /**
     * @brief Constructor to initialize a Tower object.
     * 
     * @param current_level Reference to the Level object.
     * @param position Initial position of the Tower (Vector2D).
     * @param health Initial health points of the Tower.
     * @param damage Damage inflicted by the Tower.
     * @param range Range of attack for the Tower.
     * @param attack_speed Speed of attack for the Tower.
     * @param type Type of the Tower.
     * @param price Price of the Tower.
     * @param level Level of the Tower.
     */
    Tower(Level& current_level, Vector2D& position, int health, int damage, int range, int attack_speed, int type, int price, int level);

    /**
     * @brief Destructor for the Tower.
     */
    ~Tower() { }

    /**
     * @brief Increase the level of the Tower.
     */
    void level_up();

    /**
     * @brief Get the price of the Tower.
     * 
     * @return Integer representing the price of the Tower.
     */
    int get_price();

private:
    int _price;
    int _level;
};
#endif