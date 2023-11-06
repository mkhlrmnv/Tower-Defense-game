#include "square.hpp"
#include "tower.hpp"
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
    Vector2D cent(55, 75);
    Square sq(cent);
    Vector2D pos(50, 70);
    Vector2D pos2(60, 70);
    Tower* t = new Tower(100, 100, 1, 1, pos, 50);
    Enemy* e = new Enemy(50, 50, 2, 3, pos2, 4, 7);
    sq.add_object(t);
    sq.add_object(e);
    // sq.print_info();
    return sq.get_occupied() == tower;
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
    
    if (testObjectList()){
        std::cout << "testObjectList: Passed" << std::endl;
    } else {
        std::cout << "testObjectList: Failed" << std::endl;
        fails++;
    }

    if (fails == 0){
        std::cout << "All Square test passed" << std::endl;
    } else {
        std::cout << fails << " Square test failed" << std::endl;
    }

    return fails;
}