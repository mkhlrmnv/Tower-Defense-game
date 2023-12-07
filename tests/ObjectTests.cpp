#include "object.hpp"
#include "level.hpp"
#include "vector2d.hpp"
#include <stdio.h>
#include <cassert>

// Test for Object Constructor
bool testObjectConstructor() {
    Level lv(1000, 1000, 50); // Create a level
    Vector2D pos(100, 200); // Create a position vector

    Object obj(lv, pos, 100, 10, 50, 5, 1); // Create an object

    // Check if the object properties were set correctly
    return (obj.get_position() == pos &&
            obj.get_health() == 100 &&
            obj.get_damage() == 10 &&
            obj.get_range() == 50 &&
            obj.get_attack_speed() == 5 &&
            obj.get_original_attack_speed() == 5 &&
            obj.get_type() == 1 &&
            obj.get_state() == State::none);
}

// Test for Object Getters and Setters
bool testObjectGettersAndSetters() {
    Level lv(1000, 1000, 50); // Create a level
    Vector2D pos(100, 200); // Create a position vector
    Object obj(lv, pos, 100, 10, 50, 5, 1); // Create an object

    // Test Getters
    assert(obj.get_health() == 100);
    assert(obj.get_damage() == 10);
    assert(obj.get_range() == 50);
    assert(obj.get_attack_speed() == 5);
    assert(obj.get_original_attack_speed() == 5);
    assert(obj.get_position() == pos);
    assert(obj.get_type() == 1);
    assert(obj.get_attack_counter() == 0);
    assert(obj.get_reset_counter() == 0);

    // Test Setters
    obj.set_attack_speed(6);
    obj.set_position(pos);

    assert(obj.get_health() == 100);
    assert(obj.get_damage() == 10);
    assert(obj.get_range() == 50);
    assert(obj.get_attack_speed() == 6);
    assert(obj.get_position() == Vector2D(100, 200));

    return true;
}

// Test for Object Movement
bool testObjectMovement() {
    Level lv(1000, 1000, 50); // Create a level
    Vector2D pos(100, 200); // Create a position vector
    Object obj(lv, pos, 100, 10, 50, 5, 1); // Create an object

    Vector2D new_pos(150, 250);
    obj.set_position(new_pos);

    // Check if the object's position has been updated
    assert(obj.get_position() == new_pos);

    return true;
}

// Test for Object State
bool testObjectState() {
    Level lv(1000, 1000, 50); // Create a level
    Vector2D pos(100, 200); // Create a position vector
    Object obj(lv, pos, 100, 10, 50, 5, 1); // Create an object

    obj.set_state(State::attacking_left); // Set object state to ATTACK

    // Check if the object's state has been updated
    assert(obj.get_state() == State::attacking_left);

    return true;
}

// Test for Object Distance Calculation
bool testObjectDistanceCalculation() {
    Level lv(1000, 1000, 50); // Create a level
    Vector2D pos(100, 200); // Create a position vector
    Object obj(lv, pos, 100, 10, 50, 5, 1); // Create an object

    Vector2D target_pos(150, 250);

    // Calculate distance between object and target position
    double distance = obj.distance_to(target_pos);

    return true;
}

// Test for Object Health Management
bool testObjectHealthManagement() {
    Level lv(1000, 1000, 50); // Create a level
    Vector2D pos(100, 200); // Create a position vector
    Object obj(lv, pos, 100, 10, 50, 5, 1); // Create an object

    obj.lose_health(20); // Lose health

    // Check if the object's health decreased correctly
    assert(obj.get_health() == 80);

    obj.gain_health(30); // Gain health

    // Check if the object's health increased correctly
    assert(obj.get_health() == 110);

    return true;
}

// Test for Object Attack Speed Management
bool testObjectAttackSpeedManagement() {
    Level lv(1000, 1000, 50); // Create a level
    Vector2D pos(100, 200); // Create a position vector
    Object obj(lv, pos, 100, 10, 50, 5, 1); // Create an object

    obj.gain_attack_speed(2); // Gain attack speed

    // Check if the object's attack speed decreased correctly
    assert(obj.get_attack_speed() == 3);

    obj.set_attack_speed(obj.get_original_attack_speed());
    obj.lose_attack_speed(1); // Lose attack speed

    // Check if the object's attack speed increased correctly
    assert(obj.get_attack_speed() == 6);

    return true;
}

// Test for Object Counter Management
bool testObjectCounterManagement() {
    Level lv(1000, 1000, 50); // Create a level
    Vector2D pos(100, 200); // Create a position vector
    Object obj(lv, pos, 100, 10, 50, 5, 1); // Create an object

    obj.set_attack_counter(2); // Set attack counter
    obj.set_reset_counter(3); // Set reset counter

    obj.attack_counter_up(); // Increment attack counter
    obj.reset_counter_up(); // Increment reset counter

    // Check if the counters incremented correctly
    assert(obj.get_attack_counter() == 1);
    assert(obj.get_reset_counter() == 4);

    return true;
}

int object_tests() {
    int failed_tests = 0;

    if (!testObjectConstructor()) {
        std::cout << "testObjectConstructor failed!" << std::endl;
        failed_tests++;
    } else {
        std::cout << "testObjectConstructor passed!" << std::endl;
    }

    if (!testObjectGettersAndSetters()) {
        std::cout << "testObjectGettersAndSetters failed!" << std::endl;
        failed_tests++;
    } else {
        std::cout << "testObjectGettersAndSetters passed!" << std::endl;
    }

    if (!testObjectMovement()) {
        std::cout << "testObjectMovement failed!" << std::endl;
        failed_tests++;
    } else {
        std::cout << "testObjectMovement passed!" << std::endl;
    }

    if (!testObjectState()) {
        std::cout << "testObjectState failed!" << std::endl;
        failed_tests++;
    } else {
        std::cout << "testObjectState passed!" << std::endl;
    }

    if (!testObjectDistanceCalculation()) {
        std::cout << "testObjectDistanceCalculation failed!" << std::endl;
        failed_tests++;
    } else {
        std::cout << "testObjectDistanceCalculation passed!" << std::endl;
    }

    if (!testObjectHealthManagement()) {
        std::cout << "testObjectHealthManagement failed!" << std::endl;
        failed_tests++;
    } else {
        std::cout << "testObjectHealthManagement passed!" << std::endl;
    }

    if (!testObjectAttackSpeedManagement()) {
        std::cout << "testObjectAttackSpeedManagement failed!" << std::endl;
        failed_tests++;
    } else {
        std::cout << "testObjectAttackSpeedManagement passed!" << std::endl;
    }

    if (!testObjectCounterManagement()) {
        std::cout << "testObjectCounterManagement failed!" << std::endl;
        failed_tests++;
    } else {
        std::cout << "testObjectCounterManagement passed!" << std::endl;
    }

    if (failed_tests == 0) {
        std::cout << "All Object tests passed!" << std::endl;
    } else {
        std::cout << failed_tests << " Object tests failed!" << std::endl;
    }

    return failed_tests;
}