#include "square.hpp"

// Initialize new square
Square::Square(Vector2D center):
    _center(center){}

// Returns center of the square
Vector2D Square::get_center() const {
    return _center;
}

// Returns list of all objects
std::vector<Object*> Square::get_objects() const{
    return _objects;
}

// Returns who occupies square 
int Square::get_occupied() const{
    return _occupied_by;
}

// add object to square
void Square::add_object(Object *object){
    _objects.push_back(object);
    //Update occupied_by
}

// occupies square by grass
bool Square::occupy_by_grass(){ 
    if (_occupied_by == tower || _occupied_by == road){
        return false;
    }
    _occupied_by = grass;
    _objects.clear();  // deletes tower from object list
    return true;
}

// occupies square by road
bool Square::occupy_by_road(){ 
    if (_occupied_by == tower && _occupied_by == grass) {
        return false;
    }
    _occupied_by = road;
    return true;
}

// occupies square by tower
bool Square::occupy_by_tower(){
    if (_occupied_by == tower && _occupied_by == road) {
        return false;   
    }
    _occupied_by = tower;
    return true;
}