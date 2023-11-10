#include "square.hpp"

// Initialize new square
Square::Square(Vector2D center):
    _center(center), _occupied_by(){}

// Returns center of the square
Vector2D Square::get_center() const {
    return _center;
}

// Returns who occupies square 
int Square::get_occupied() const{
    return _occupied_by;
}

void Square::print_info(){
    std::cout << "Square with center point at " << _center.x << " " << _center.y 
        << " is occupied " << get_occupied() << std::endl;
}

// occupies square by grass
bool Square::occupy_by_grass(){ 
    if (_occupied_by == tower || _occupied_by == road){
        return false;
    }
    _occupied_by = grass;
    return true;
}

// occupies square by road
bool Square::occupy_by_road(){ 
    if (_occupied_by == tower) {
        return false;
    }
    _occupied_by = road;
    return true;
}

// occupies square by tower
bool Square::occupy_by_tower(){
    if (_occupied_by == tower || _occupied_by == road) {
        return false;   
    }
    _occupied_by = tower;
    return true;
}