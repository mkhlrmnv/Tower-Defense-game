#ifndef TOWER_HPP
#define TOWER_HPP

#include "object.hpp"

class Tower: public Object {
public:
    Tower(Level& current_level, int health, int damage, int range, int attack_speed, Vector2D position, int type, int price, int level) : 
            Object(current_level, health, damage, range, attack_speed, position, type), _price(price), _level(level) {}

    void level_up() {
        gain_damage(10 * _level);
        gain_health(50 * _level);
        gain_range(5 * _level);
        gain_attack_speed(150 * _level);
    }
    
    // std::vector<std::pair<double, Enemy*>> enemy_distances() {
    //     std::vector<std::pair<double, Enemy*>> distances;

    //     for (auto it = _enemy_list->begin(); it != _enemy_list->end(); ++it) {
    //         Enemy* obj = *it;
    //         double dist = this->distance_to(obj->get_position());
    //         distances.push_back(std::make_pair(dist, obj));
    //     }

    //     // Sort the objects by distance in ascending order
    //     std::sort(distances.begin(), distances.end(), [](const std::pair<double, Enemy*> a, const std::pair<double, Enemy*> b) {
    //         return a.first < b.first;
    //     });

    //     return distances;
    // }

private:
    int _price;
    int _level;
};

#endif