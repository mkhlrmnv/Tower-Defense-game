#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "object.hpp"

class Enemy: public Object {
public:
    Enemy(Level& level, int health, int damage, int range, int attack_speed, Vector2D position, int type, int speed, int defense) : 
            Object(level, health, damage, range, attack_speed, position, type), _speed(speed), _defense(defense) {}

    void move(Vector2D targetPosition) {
        set_position(targetPosition);
    }

    // std::vector<std::pair<double, Tower*>> tower_distances() {
    //     std::vector<std::pair<double, Tower*>> distances;

    //     for (auto it = _tower_list->begin(); it != _tower_list->end(); ++it) {
    //         Tower* obj = *it;
    //         double dist = this->distance_to(obj->get_position());
    //         distances.push_back(std::make_pair(dist, obj));
    //     }

    //     // Sort the objects by distance in ascending order
    //     std::sort(distances.begin(), distances.end(), [](const std::pair<double, Tower*> a, const std::pair<double, Tower*> b) {
    //         return a.first < b.first;
    //     });

    //     return distances;
    // }

private:
    int _speed;
    int _defense;
};

#endif