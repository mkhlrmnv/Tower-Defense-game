#include "enemy.hpp"
#include "level.hpp"
#include "attack_types.hpp"

Enemy::Enemy(Level& level, int health, int damage, int range, int attack_speed, Vector2D position, int type, int speed, int defense) : 
            Object(level, health, damage, range, attack_speed, position, type), _speed(speed), _defense(defense) {}

int Enemy::get_speed() const {
    return _speed;
}

int Enemy::get_defense() const {
    return _defense;
}

std::vector<Vector2D> Enemy::get_route() const{
    return _route;
}

void Enemy::set_route_position(Vector2D position) {
    _route.push_back(position);
}

Vector2D Enemy::get_prev_pos(){
    return _prev_pos;
}

void Enemy::set_prev_pos(Vector2D pos){
    _prev_pos = pos;
}

void Enemy::move() {

    std::vector<Vector2D> route = get_route();
    // if current square center is different then previous center of previous position square
    // previous gets added to route list
    if (!route.empty()){
        if (get_level_reference().get_square_by_pos(get_position())->get_center() !=  get_level_reference().get_square_by_pos(get_prev_pos())->get_center()){
            set_route_position(get_level_reference().get_square_by_pos(get_prev_pos())->get_center());
        }
    } else {
        if (get_level_reference().get_square_by_pos(get_position())->get_center() != get_level_reference().get_first_road()->get_center()){
            set_route_position(get_level_reference().get_first_road()->get_center());
        }
    }

    Vector2D next_position; // variable for storing new position
    Vector2D pos; // variable for calculating next square position
    bool moved = false; // variable, that not allows to move in two directions at the same time
    for (Direction direction : get_level_reference().next_road(this)) { // for loop that goes throw possible directions
        switch (direction) // switch case for each direction
        {
        case up:
            // calculating center point of next square
            pos = get_level_reference().get_square_by_pos(Vector2D(get_position().x, get_position().y - get_level_reference().get_square_size()))->get_center();
            // if vector that stores all squares that enemy has gone throw isn't empty
            if (!get_route().empty()){
                /*
                Checks if previous squares center point isn't the same where now enemy wants to go
                and enemy hasn't moved on this call and if previous direction is higher or the same that now
                (Last thing is made so enemy doesn't go up if on previous call enemy gone down)
                If all this is true enemy gets new position and variable moved is switched to true, so enemy doesn't change direction on this call
                */
                if (get_route().back() != pos && !moved && get_prev_pos().y >= get_position().y){
                    next_position = Vector2D(get_position().x, get_position().y - get_speed());
                    set_state(State::walking_right);
                    moved = true;
                }
            } else {
                // Checks that enemy hasn't moved on this call, if true 
                // enemy gets new position and variable moved is switched to true, so enemy doesn't change direction on this call
                if (!moved){
                    next_position = Vector2D(get_position().x, get_position().y - get_speed());
                    set_state(State::walking_right);
                    moved = true;
                }
            }
            break;
        case down:
            // If statements explained in case up
            pos = get_level_reference().get_square_by_pos(Vector2D(get_position().x, get_position().y + get_level_reference().get_square_size()))->get_center();
            if (!get_route().empty()){
                if (get_route().back() != pos && !moved && get_prev_pos().y <= get_position().y){
                    next_position = Vector2D(get_position().x, get_position().y + get_speed());
                    set_state(State::walking_right);
                    moved = true;
                }
            } else {
                if (!moved){
                    next_position = Vector2D(get_position().x, get_position().y + get_speed());
                    set_state(State::walking_right);
                    moved = true;
                }
            }
            break;
        case right:
            // If statements explained in case up
            pos = get_level_reference().get_square_by_pos(Vector2D(get_position().x + get_level_reference().get_square_size(), get_position().y))->get_center();
            if (!get_route().empty()){
                if (get_route().back() != pos && !moved && get_prev_pos().x <= get_position().x){
                    next_position = Vector2D(get_position().x + get_speed(), get_position().y);
                    set_state(State::walking_right);
                    moved = true;
                }
            } else {
                if (!moved){
                    next_position = Vector2D(get_position().x + get_speed(), get_position().y);
                    set_state(State::walking_right);
                    moved = true;
                }
            }
            break;
        case left:
            // If statements explained in case up
            pos = get_level_reference().get_square_by_pos(Vector2D(get_position().x - get_level_reference().get_square_size(), get_position().y))->get_center();
            if (!get_route().empty()){
                if (get_route().back() != pos && !moved && get_prev_pos().x >= get_position().x){
                    next_position = Vector2D(get_position().x - get_speed(), get_position().y); // get_level_reference().get_square_by_pos(get_position())->get_center().y
                    set_state(State::walking_left);
                    moved = true;
                }
            } else {
                if (!moved){
                    next_position = Vector2D(get_position().x - get_speed(), get_position().y);
                    moved = true;
                }
            }
            break;
        }
    }

    // if next position isn't the same that current position
    // it means that enemy has moved and we can set current position as 
    // previous one
    if ((get_position() != next_position && next_position.x != 0 && next_position.y != 0)){
        set_prev_pos(get_position());
    }

    // if next position is out of the bounds, enemy gets deleted and one live is taken away from player
    if (next_position.x >= 800 || next_position.y >= 800 || next_position.y <= 0 || next_position.x <= 0){
        get_level_reference().take_lives(1);
        get_level_reference().remove_enemy(this);
        // std::cout << "uda buga" << std::endl;
    } else { 
        // If next position is in the bounds, enemy's position is set to next position
        // std::cout << get_position().x - next_position.x << " " << get_position().y - next_position.y << std::endl;
        // std::cout << get_position() << std::endl;
        set_position(next_position);
    }
    // set_route_position(get_position());
    // set_position(next_position);
}
