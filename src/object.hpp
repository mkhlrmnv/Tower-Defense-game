#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "vector2d.hpp"

#include <vector>
#include <math.h>
#include <algorithm>
#include <stdexcept>
#include <chrono>
#include <thread>

/**
 * @brief Forward declaration of level class.
 */
class Level;

enum State{none, walking_right, walking_left, attacking_right, attacking_left, dying};


/**
 * @brief Class that defines the behavior of all objects in the game.
 */
class Object {
public:

    /**
     * @brief Constructor to initialize an Object.
     * 
     * @param level Reference to the Level object.
     * @param position Initial position of the Object (Vector2D).
     * @param health Initial health points of the Object.
     * @param damage Damage inflicted by the Object.
     * @param range Range of attack for the Object.
     * @param attack_speed Speed of attack for the Object.
     * @param type Type of the Object.
     */
    Object(Level& level, Vector2D& position, int health, int damage, int range, int attack_speed, int type);

    /**
     * @brief Virtual destructor for Object.
     */
    virtual ~Object();

    /**
     * @brief Get the damage value of the object.
     * 
     * @return Integer representing the damage value.
     */
    int get_damage() const;

    /**
     * @brief Get the health value of the object.
     * 
     * @return Integer representing the health value.
     */
    int get_health() const;

    /**
     * @brief Get the attack range of the object.
     * 
     * @return Integer representing the attack range.
     */
    int get_range() const;

    /**
     * @brief Get the attack speed of the object.
     * 
     * @return Integer representing the attack speed.
     */
    int get_attack_speed() const;

    /**
     * @brief Get the original attack speed of the object.
     * 
     * @return Integer representing the original attack speed.
     */
    int get_original_attack_speed() const;

    /**
     * @brief Get the position of the object.
     * 
     * @return Vector2D object representing the position.
     */
    const Vector2D get_position() const;

    /**
     * @brief Get the type of the object.
     * 
     * @return Integer representing the type of the object.
     */
    int get_type() const;

    /**
     * @brief Get a reference to the Level object associated with this object.
     * 
     * @return Reference to the Level object.
     */
    Level& get_level_reference() const;

    /**
     * @brief Get the attack counter value of the object.
     * 
     * @return Integer representing the attack counter value.
     */
    int get_attack_counter() const;

    /**
     * @brief Get the reset counter value of the object.
     * 
     * @return Integer representing the reset counter value.
     */
    int get_reset_counter() const;

    /**
     * @brief Set the position of the object.
     * 
     * @param position New position of the object (Vector2D).
     */
    void set_position(const Vector2D& position);

    /**
     * @brief Set the attack counter value of the object.
     * 
     * @param amount New value for the attack counter.
     */
    void set_attack_counter(const int amount);

    /**
     * @brief Set the reset counter value of the object.
     * 
     * @param amount New value for the reset counter.
     */
    void set_reset_counter(const int amount);

    /**
     * @brief Set the attack speed of the object.
     * 
     * @param amount New value for the attack speed.
     */
    void set_attack_speed(const int amount);

    /**
     * @brief Set the original attack speed of the object.
     * 
     * @param amount New value for the original attack speed.
     */
    void set_original_attack_speed(const int amount);

    /**
     * @brief Increment the attack counter value by one.
     */
    void attack_counter_up();

    /**
     * @brief Increment the reset counter value by one.
     */
    void reset_counter_up();

    /**
     * @brief Increase the damage value of the object.
     * 
     * @param amount Amount by which the damage is increased.
     */
    void gain_damage(int amount);

    /**
     * @brief Increase the health value of the object.
     * 
     * @param amount Amount by which the health is increased.
     */
    void gain_health(int amount);

    /**
     * @brief Increase the attack range of the object.
     * 
     * @param amount Amount by which the attack range is increased.
     */
    void gain_range(int amount);

    /**
     * @brief Increase the attack speed of the object.
     * 
     * @param amount Amount by which the attack speed is increased.
     */
    void gain_attack_speed(int amount);

    /**
     * @brief Calculate the distance between the object and a target position.
     * 
     * @param target_position The position of the target (Vector2D).
     * @return Double representing the distance between the object and the target.
     */
    double distance_to(const Vector2D& target_position);

    /**
     * @brief Decrease the health value of the object.
     * 
     * @param amount Amount by which the health is decreased.
     */
    void lose_health(int amount);

    /**
     * @brief Decrease the attack speed of the object.
     * 
     * @param amount Amount by which the attack speed is decreased.
     */
    void lose_attack_speed(int amount);

    /**
     * @brief Get the current state of the object.
     * 
     * @return State enum representing the current state.
     */
    State get_state();

    /**
     * @brief Get the reset wait time for all objects.
     * 
     * @return Integer the amount of time to wait.
     */
    int get_wait_time() const;

    /**
     * @brief Set the state of the object.
     * 
     * @param state The new state of the object.
     */
    void set_state(State state);

    /**
     * @brief Virtual method for Object's attack action.
     * 
     * @return true if the attack is successful, false otherwise.
     */
    virtual bool attack();

private:
    Level& _level;
    int _health_points;
    int _damage;
    int _range;
    int _attack_speed;
    int _original_attack_speed = 0;
    int _attack_counter = 0;
    int _reset_counter = 0;
    int _reset_wait_time = 100;
    Vector2D _position;
    int _type;
    State _state;
};

#endif