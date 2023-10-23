#include "square.hpp"

Square::Square(Vector2D center):
    _center(center) {}

const Vector2D Square::get_Center() const {
    return _center;
}

const std::vector<Object> Square::get_Objects() const{
    return _objects;
}


const int Square::get_Occupied() const{
    return _occupied_by;
}