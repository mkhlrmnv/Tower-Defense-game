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
    //Update occupied_by
}

void Square::occupy_by_grass(){
    _occupied_by = grass;
}

void Square::occupy_by_road(){
    _occupied_by = road;
}

void Square::occupy_by_tower(){
    _occupied_by = road;
}