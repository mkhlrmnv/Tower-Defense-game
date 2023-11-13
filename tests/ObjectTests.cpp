#include "object.hpp"
#include "vector2d.hpp"
#include "attack_types.hpp"
#include "level.hpp"
#include <iostream>

bool testObjectHealth() {
    Vector2D position(0, 0);
    Level level(1000, 100, 3);
    Object obj(level, 100, 20, 10, 1000, position, BASIC);
    return obj.get_health() == 100;
}

bool testObjectPosition() {
    Vector2D position(0, 0);
    Vector2D newPosition(10, 20);
    Level level(1000, 100, 3);
    Object obj(level, 100, 20, 10, 1000, position, BASIC);

    // Check the initial position
    if (obj.get_position() != position) {
        return false;
    }

    // Set a new position and check if it's updated
    obj.set_position(newPosition);
    if (obj.get_position() != newPosition) {
        return false;
    }

    return true;
}

bool testObjectDamage() {
    Vector2D position(0, 0);
    Level level(1000, 100, 3);
    Object obj(level, 100, 20, 10, 1000, position, BASIC);
    return obj.get_damage() == 20;
}

bool testObjectRange() {
    Vector2D position(0, 0);
    Level level(1000, 100, 3);
    Object obj(level, 100, 20, 10, 1000, position, BASIC);
    return obj.get_range() == 10;
}

bool testObjectAttackSpeed() {
    Vector2D position(0, 0);
    Level level(1000, 100, 3);
    Object obj(level, 100, 20, 10, 1000, position, BASIC);
    return obj.get_attack_speed() == 1000;
}

bool testObjectGetType() {
    Vector2D position(0, 0);
    Level level(1000, 100, 3);
    Object obj(level, 100, 20, 10, 1000, position, BASIC);
    return obj.get_type() == BASIC;
}

bool testObjectGainDamage() {
    Vector2D position(0, 0);
    Level level(1000, 100, 3);
    Object obj(level, 100, 20, 10, 1000, position, BASIC);
    obj.gain_damage(5);
    return obj.get_damage() == 25;
}

bool testObjectGainHealth() {
    Vector2D position(0, 0);
    Level level(1000, 100, 3);
    Object obj(level, 100, 20, 10, 1000, position, BASIC);
    obj.gain_health(10);
    return obj.get_health() == 110;
}

bool testObjectGainRange() {
    Vector2D position(0, 0);
    Level level(1000, 100, 3);
    Object obj(level, 100, 20, 10, 1000, position, BASIC);
    obj.gain_range(2);
    return obj.get_range() == 12;
}

bool testObjectGainAttackSpeed() {
    Vector2D position(0, 0);
    Level level(1000, 100, 3);
    Object obj(level, 100, 20, 10, 1000, position, BASIC);
    obj.gain_attack_speed(200);
    return obj.get_attack_speed() == 1200;
}

bool testObjectDistanceTo() {
    Vector2D position(0, 0);
    Level level(1000, 100, 3);
    Object obj(level, 100, 20, 10, 1000, position, BASIC);
    Vector2D targetPosition(3, 4);
    double distance = obj.distance_to(targetPosition);
    // Check if the distance is calculated correctly (considering the distance formula)
    return distance == 5.0;
}

bool testObjectLoseHealth() {
    Vector2D position(0, 0);
    Level level(1000, 100, 3);
    Object obj(level, 100, 20, 10, 1000, position, BASIC);
    obj.lose_health(30);
    return obj.get_health() == 70;
}

static int object_tests() {
    int testsFailed = 0;

    if (testObjectHealth()) {
        std::cout << "testObjectHealth: Passed" << std::endl;
    } else {
        std::cout << "testObjectHealth: Failed" << std::endl;
        testsFailed++;
    }

    if (testObjectPosition()) {
        std::cout << "testObjectPosition: Passed" << std::endl;
    } else {
        std::cout << "testObjectPosition: Failed" << std::endl;
        testsFailed++;
    }

    if (testObjectDamage()) {
        std::cout << "testObjectDamage: Passed" << std::endl;
    } else {
        std::cout << "testObjectDamage: Failed" << std::endl;
        testsFailed++;
    }

    if (testObjectRange()) {
        std::cout << "testObjectRange: Passed" << std::endl;
    } else {
        std::cout << "testObjectRange: Failed" << std::endl;
        testsFailed++;
    }

    if (testObjectAttackSpeed()) {
        std::cout << "testObjectAttackSpeed: Passed" << std::endl;
    } else {
        std::cout << "testObjectAttackSpeed: Failed" << std::endl;
        testsFailed++;
    }

    if (testObjectGetType()) {
        std::cout << "testObjectGetType: Passed" << std::endl;
    } else {
        std::cout << "testObjectGetType: Failed" << std::endl;
        testsFailed++;
    }

    if (testObjectGainDamage()) {
        std::cout << "testObjectGainDamage: Passed" << std::endl;
    } else {
        std::cout << "testObjectGainDamage: Failed" << std::endl;
        testsFailed++;
    }

    if (testObjectGainHealth()) {
        std::cout << "testObjectGainHealth: Passed" << std::endl;
    } else {
        std::cout << "testObjectGainHealth: Failed" << std::endl;
        testsFailed++;
    }

    if (testObjectGainRange()) {
        std::cout << "testObjectGainRange: Passed" << std::endl;
    } else {
        std::cout << "testObjectGainRange: Failed" << std::endl;
        testsFailed++;
    }

    if (testObjectGainAttackSpeed()) {
        std::cout << "testObjectGainAttackSpeed: Passed" << std::endl;
    } else {
        std::cout << "testObjectGainAttackSpeed: Failed" << std::endl;
        testsFailed++;
    }

    if (testObjectDistanceTo()) {
        std::cout << "testObjectDistanceTo: Passed" << std::endl;
    } else {
        std::cout << "testObjectDistanceTo: Failed" << std::endl;
        testsFailed++;
    }

    if (testObjectLoseHealth()) {
        std::cout << "testObjectLoseHealth: Passed" << std::endl;
    } else {
        std::cout << "testObjectLoseHealth: Failed" << std::endl;
        testsFailed++;
    }

    if (testsFailed == 0) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return testsFailed;
}
