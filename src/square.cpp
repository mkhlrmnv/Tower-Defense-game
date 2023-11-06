#include "square.hpp"

// Initialize new square
Square::Square(Vector2D center):
    _center(center){}

// Returns center of the square
Vector2D Square::get_center() const {
    return _center;
}

// Returns who occupies square 
int Square::get_occupied() const{
    return _occupied_by;
}

void Square::print_info(){
    std::cout << "Square with center point at " << _center.x << " " << _center.y << " is occupied " << get_occupied() << std::endl;
    /*std::cout << "Has objects in it:\n";
    for (auto* obj : _objects){
        if (dynamic_cast<Tower*>(obj)){
            std::cout << "Tower with HP: " << obj->get_health() << " damage: " << obj->get_damage()
                << " range: " << obj->get_range() << " attack speed: " << obj->get_attack_speed()
                << " position: " << obj->get_position().x << " " << obj->get_position().y << " price: " << std::endl; // TODO: get_price()
        } else if(dynamic_cast<Enemy*>(obj)) {
            std::cout << "Enemy with HP: " << obj->get_health() << " damage: " << obj->get_damage()
                << " range: " << obj->get_range() << " attack speed: " << obj->get_attack_speed()
                << " position: " << obj->get_position().x << " " << obj->get_position().y << " speed: " << std::endl; // TODO: get_speed()
        }
    }*/
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