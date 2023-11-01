#include "square.hpp"
#include <iostream>

bool testCenter(){
    Vector2D cent(2, 3);
    Square sq(cent);
    return sq.get_center() == cent;
}

bool testOccupied(){
    Vector2D cent(2, 3), cent2(4, 5), cent3(6, 7);
    Square sq(cent), sq2(cent2), sq3(cent3);
    sq.occupy_by_grass();
    sq2.occupy_by_road();
    // sq3.occupy_by_tower(); TODO: when tower class is ready
    return sq.get_occupied() == grass && sq2.get_occupied() == road /*&& sq3.get_occupied() == tower*/;
}

bool testObjectList(){
    // TODO: when object class is complete
    return true;
}

static int square_test() {
    int fails = 0;

    if (testCenter()){
        std::cout << "testCenter: Passed" << std::endl;
    } else {
        std::cout << "testCenter: Failed" << std::endl;
        fails++;
    }

    if (testOccupied()){
        std::cout << "testOccupied: Passed" << std::endl;
    } else {
        std::cout << "testOccupied: Failed" << std::endl;
        fails++;
    }

    /*
    if (testObject()){
        std::cout << "testObjectList: Passed" << std::endl;
    } else {
        std::cout << "testObjectList: Failed" << std::endl;
        fails++;
    }
    */

    if (fails == 0){
        std::cout << "All test passed" << std::endl;
    } else {
        std::cout << fails << " test failed" << std::endl;
    }

    return fails;
}