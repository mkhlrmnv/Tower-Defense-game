#ifndef SQUARE_HPP
#define SQUARe_HPP

#include "vector2d.hpp"
#include "object.hpp"

#include <vector>

enum occupied_type{
    tower, grass, road
};


class Square {
public:
    Square(/* args */);

    ~Square();

private:
    Vector2D center;
    std::vector<Object> objects;
    occupied_type occupied_by;
};


#endif