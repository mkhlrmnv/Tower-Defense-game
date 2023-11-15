#include "enemy.hpp"
#include <iostream>

bool testEnemySpeed() {
    Vector2D position(0, 0);
    Level level(1000, 100, 3);
    Enemy enemy(level, 100, 20, 5, 3, position, 1, 8, 10);
    return enemy.get_speed() == 8;
}

bool testEnemyDefense() {
    Vector2D position(0, 0);
    Level level(1000, 100, 3);
    Enemy enemy(level, 100, 20, 5, 3, position, 1, 8, 10);
    return enemy.get_defense() == 10;
}

bool testEnemySetTargetPositionAndGetRoute() {
    Vector2D position(0, 0);
    Level level(1000, 100, 3);
    Enemy enemy(level, 100, 20, 5, 3, position, 1, 8, 10);

    Vector2D targetPosition(10, 10);
    enemy.set_route_position(targetPosition);
    std::vector<Vector2D> route = enemy.get_route();

    return route.size() == 2 &&
           route[0] == Vector2D(0, 0) &&
           route[1] == targetPosition &&
           enemy.get_position() == targetPosition;
}

int enemy_tests() {
    int testsFailed = 0;

    if (testEnemySpeed()) {
        std::cout << "testEnemySpeed: Passed" << std::endl;
    } else {
        std::cout << "testEnemySpeed: Failed" << std::endl;
        testsFailed++;
    }

    if (testEnemyDefense()) {
        std::cout << "testEnemyDefense: Passed" << std::endl;
    } else {
        std::cout << "testEnemyDefense: Failed" << std::endl;
        testsFailed++;
    }

    if (testEnemySetTargetPositionAndGetRoute()) {
        std::cout << "testEnemySetTargetPositionAndGetRoute: Passed" << std::endl;
    } else {
        std::cout << "testEnemySetTargetPositionAndGetRoute: Failed" << std::endl;
        testsFailed++;
    }

    if (testsFailed == 0) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return testsFailed;
}