#include "src/square.hpp"
#include "vector2d.hpp"
#include <iostream>

bool testCenter(){
    Vector2D cent(2, 3);
    Square sq(cent);
    return sq.get_Center() == cent;
}

bool testOccupied(){
    Vector2D cent(2, 3), cent2(4, 5), cent3(6, 7);
    Square sq(cent), sq2(cent2), sq3(cent3);
    sq.occupy_by_grass();
    sq2.occupy_by_road();
    sq3.occupy_by_tower()
    return sq.

}