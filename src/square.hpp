#ifndef SQUARE_HPP
#define SQUARE_HPP

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
    Vector2D get_center() const;

    // Returns list of objects that are in the square
    std::vector<Object> get_objects() const;

    // Returns what is occupuing square
    int get_occupied() const;

    // Adds object to the square
    void add_object(Object object);

    // Occupies square by something
    bool occupy_by_grass();
    bool occupy_by_road();
    bool occupy_by_tower(Object obj);

private:
    Vector2D _center;
    std::vector<Object> _objects;
    occupied_type _occupied_by;
};


#endif