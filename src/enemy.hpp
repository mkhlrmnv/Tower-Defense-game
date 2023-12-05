#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "object.hpp"

/**
 * @brief Enemy class for handling all enemies
*/
class Enemy : public Object {
public:
    Enemy(Level& level, Vector2D& position, int health, int damage, int range, int attack_speed, int type, int speed, int defense, int size);

    /**
     * @brief Destructor for the Enemy.
     */
    ~Enemy() { }

    /**
     * @brief Get the speed attribute of the Enemy.
     * 
     * @return Integer representing the speed attribute.
     */
    int get_speed() const;

    /**
     * @brief Get the original speed attribute of the Enemy.
     * 
     * @return Integer representing the original speed attribute.
     */
    int get_original_speed() const;

    /**
     * @brief Get the defense attribute of the Enemy.
     * 
     * @return Integer representing the defense attribute.
     */
    int get_defense() const;

    void lose_speed(int amount);

    /**
     * @brief Set the speed attribute of the Enemy.
     * 
     * @param amount New value for the speed attribute.
     */
    void set_speed(int amount);

    /**
     * @brief Move the Enemy based on its behavior logic.
     */
    void move();

    // void State get_state(); // Uncomment and add Doxygen-style comment if required

    // bool attack(); // Uncomment and add Doxygen-style comment if required

    /**
     * @brief Get the route of the Enemy.
     * 
     * @return Vector of Vector2D representing the route of the Enemy.
     */
    std::vector<Vector2D> get_route() const;

    /**
     * @brief Set the route position for the Enemy.
     * 
     * @param position New position to be set on the route (Vector2D).
     */
    void set_route_position(Vector2D position);

    /**
     * @brief Get the previous position of the Enemy.
     * 
     * @return Vector2D representing the previous position of the Enemy.
     */
    Vector2D get_prev_pos();

    /**
     * @brief Set the previous position of the Enemy.
     * 
     * @param pos New previous position to be set (Vector2D).
     */
    void set_prev_pos(Vector2D pos);

private:
    Vector2D _prev_pos;
    int _speed;
    int _original_speed = 0;
    int _defense;
    int _size;
    std::vector<Vector2D> _route;
};

#endif