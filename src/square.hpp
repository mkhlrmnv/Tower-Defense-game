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
    Square(Vector2D center);

    ~Square() { }

    // returns center cordinates of square
    const Vector2D get_Center() const;

    // Returns list of objects that are in the square
    const std::vector<Object> get_Objects() const;

    // Returns what is occupuing square
    const int get_Occupied() const;

    // Adds object to the square
    void add_Object(Object object);

    // Occupies square by something
    void occupy_by_grass();
    void occupy_by_road();
    void occupy_by_tower();

private:
    Vector2D _center;
    std::vector<Object> _objects;
    occupied_type _occupied_by;
};


#endif