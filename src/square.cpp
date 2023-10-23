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

void Square::add_Object(Object object){
    _objects.push_back(object);
    //Update oocupied_by
}

void Square::make_grass(){
    _occupied_by = grass;
}