#include "basic_enemy.hpp"

Basic_Enemy::Basic_Enemy(Level& level, int health, int damage, int range, int attack_speed, Vector2D& position, int type, int speed, int defense) :
    Enemy(level, health, damage, range, attack_speed, position, type, speed, defense) {}

void Basic_Enemy::attack() {
    double multiplier;
    Level& level_reference = get_level_reference();

    if (!level_reference.get_towers().empty()) {
        for (auto& tower : level_reference.get_towers()) {

            double dist = this->distance_to(tower->get_position());

            if (dist <= this->get_range()) {
                multiplier = check_type_multiplier(tower, this);
                tower->lose_health(this->get_damage() * multiplier);
                break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(this->get_attack_speed()));
    }
}

void Basic_Enemy::move() {
    Vector2D next_position;
    for (Direction direction : get_level_reference().next_road(this)) {
        if (direction == up) {
            Vector2D pos = get_level_reference().get_grid()[get_position().x][get_position().y - get_level_reference().get_square_size()]->get_center();
            for (auto route_pos : get_route()) {
                if (route_pos != next_position) {
                    next_position = pos;
                }
            }
            
        } else if (direction == down) {
            Vector2D pos = get_level_reference().get_grid()[get_position().x][get_position().y + get_level_reference().get_square_size()]->get_center();
            for (auto route_pos : get_route()) {
                if (route_pos != next_position) {
                    next_position = pos;
                }
            }
        } else if (direction == right) {
            Vector2D pos = get_level_reference().get_grid()[get_position().x + get_level_reference().get_square_size()][get_position().y]->get_center();
            for (auto route_pos : get_route()) {
                if (route_pos != next_position) {
                    next_position = pos;
                }
            }
            
        } else if (direction == left) {
            Vector2D pos = get_level_reference().get_grid()[get_position().x - get_level_reference().get_square_size()][get_position().y]->get_center();
            for (auto route_pos : get_route()) {
                if (route_pos != next_position) {
                    next_position = pos;
                }
            }
        }
    }

    set_route_position(get_position());
    set_position(next_position);
}