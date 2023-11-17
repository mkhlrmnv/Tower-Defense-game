#include "basic_enemy.hpp"
#include "level.hpp"

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
    Vector2D pos;
    bool moved = false;
    for (Direction direction : get_level_reference().next_road(this)) {
        switch (direction)
        {
        case up:
            pos = get_level_reference().get_square_by_pos(Vector2D(get_position().x, get_position().y - get_level_reference().get_square_size()))->get_center();
            if (!get_route().empty()){
                if (get_route().back() != pos && !moved && get_prev_pos().y >= get_position().y){
                    next_position = Vector2D(get_level_reference().get_square_by_pos(get_position())->get_center().x, get_position().y - get_speed());
                    moved = true;
                }
            } else {
                next_position = Vector2D(get_level_reference().get_square_by_pos(get_position())->get_center().x, get_position().y - get_speed());
            }
            break;
        case down:
            pos = get_level_reference().get_square_by_pos(Vector2D(get_position().x, get_position().y + get_level_reference().get_square_size()))->get_center();
            if (!get_route().empty()){
                if (get_route().back() != pos && !moved && get_prev_pos().y <= get_position().y){
                    next_position = Vector2D(get_level_reference().get_square_by_pos(get_position())->get_center().x, get_position().y + get_speed());
                    moved = true;
                }
            } else {
                next_position = Vector2D(get_level_reference().get_square_by_pos(get_position())->get_center().x, get_position().y + get_speed());
            }
            break;
        case right:
            pos = get_level_reference().get_square_by_pos(Vector2D(get_position().x + get_level_reference().get_square_size(), get_position().y))->get_center();
            if (!get_route().empty()){
                if (get_route().back() != pos && !moved && get_prev_pos().x <= get_position().x){
                    next_position = Vector2D(get_position().x + get_speed(), get_level_reference().get_square_by_pos(get_position())->get_center().y);
                    moved = true;
                }
            } else {
                next_position = Vector2D(get_position().x + get_speed(), get_level_reference().get_square_by_pos(get_position())->get_center().y);
            }
            break;
        case left:
            pos = get_level_reference().get_square_by_pos(Vector2D(get_position().x - get_level_reference().get_square_size(), get_position().y))->get_center();
            if (!get_route().empty()){
                if (get_route().back() != pos && !moved && get_prev_pos().x >= get_position().x){
                    next_position = Vector2D(get_position().x - get_speed(), get_level_reference().get_square_by_pos(get_position())->get_center().y);
                    moved = true;
                }
            } else {
                next_position = Vector2D(get_position().x - get_speed(), get_level_reference().get_square_by_pos(get_position())->get_center().y);
            }
            break;
        }
    }

    if (get_position() != next_position){
        set_prev_pos(get_position());
    }

    if (next_position.x < 0){
        next_position.x = 0;
    }
    if (next_position.y < 0){
        next_position.y = 0;
    }

    std::vector<Vector2D> route = get_route();
    if (!route.empty()){
        if (route.back() !=  get_level_reference().get_square_by_pos(get_position())->get_center()){
            set_route_position(get_level_reference().get_square_by_pos(get_position())->get_center());
        }
    } else {
        set_route_position(get_level_reference().get_square_by_pos(get_position())->get_center());
    }

    if (next_position.x > get_level_reference().get_square_size()*10 || next_position.y > get_level_reference().get_square_size()*10){
        get_level_reference().remove_enemy(this);
        get_level_reference().take_lives(1);
    } else {
        set_position(next_position);
    }
    // set_route_position(get_position());
    // set_position(next_position);
}