#include "object.hpp"
#include "vector2D.hpp"
#include <iostream>

bool testObjectHealth() {
    Vector2D position(0, 0);
    Object obj(100, 20, 10, 1000, position, BASIC);
    return obj.get_health() == 100;
}

bool testObjectPosition() {
    Vector2D initialPosition(0, 0);
    Vector2D newPosition(10, 20);
    Object obj(100, 10, 5, 2, initialPosition, BASIC);

    // Check the initial position
    if (obj.get_position() != initialPosition) {
        return false;
    }

    // Set a new position and check if it's updated
    obj.set_position(newPosition);
    if (obj.get_position() != newPosition) {
        return false;
    }

    return true;
}

// bool testObjectAttack() {
//     Vector2D position(0, 0);
//     Object obj(100, 10, 5, 2, position);
//     Object target(100, 0, 0, 0, position);

//     obj.attack(); // Implement your attack logic here
//     target.attack();

//     // Verify that the target object lost health after the attack
//     return target.get_health() < 100;
// }

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

    // if (testObjectAttack()) {
    //     std::cout << "testObjectAttack: Passed" << std::endl;
    // } else {
    //     std::cout << "testObjectAttack: Failed" << std::endl;
    //     allTestsPass = false;
    // }

    if (testsFailed == 0) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return testsFailed;
}
