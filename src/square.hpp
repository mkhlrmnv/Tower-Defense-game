#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "vector2d.hpp"
#include "object.hpp"
#include <iostream>
#include "tower.hpp"
#include "enemy.hpp"

#include <vector>

enum occupied_type{
    tower, grass, road
};


class Square {
public:
    Square(Vector2D center);

    ~Square() { }

    // returns center cordinates of square
    Vector2D get_center() const;

    // Returns what is occupuing square
    int get_occupied() const;

    void print_info();

    // Occupies square by something
    bool occupy_by_grass();
    bool occupy_by_road();
    bool occupy_by_tower();

private:
    Vector2D _center;
    occupied_type _occupied_by;
};


#endif