#include "basic_enemy.hpp"

#include <chrono>
#include <thread>

Basic_Enemy::Basic_Enemy() :
    Enemy(50, 10, 20, 1000, Vector2D(0,0), NEUTRAL, 10, 5) {}

Basic_Enemy::Basic_Enemy(int health, int damage, int range, int attack_speed, Vector2D& position, int type, int speed, int defense) :
    Enemy(health, damage, range, attack_speed, position, type, speed, defense) {}

void Basic_Enemy::attack() {
    double multiplier;
    auto closestObjects = distances();

    if (!closestObjects.empty()) {
        if (closestObjects[0].first < this->get_range()) {
            multiplier = check_type_multiplier(this, closestObjects[0].second);
            closestObjects[0].second->lose_health(this->get_damage() * multiplier);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(this->get_attack_speed()));
    }
}