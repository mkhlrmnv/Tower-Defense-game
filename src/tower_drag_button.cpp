#include "tower_drag_button.hpp"
#include <iostream>

TowerDragButton::TowerDragButton(const std::string& price, sf::Vector2f size, sf::Vector2f position, sf::Color color,  sf::Texture obj_texture, int tower_type) : 
Button(price, size, position, color), _texture(obj_texture), _tower_type(tower_type), _drag_flag(false){

    
    _drawable_dragging_tower.setTexture(_texture);
    _drawable_dragging_tower.setScale({_scale, _scale});
    _drawable_dragging_tower.setPosition(_position);

    _drawable_tower.setTexture(_texture);
    _drawable_tower.setScale({_scale, _scale});
    _drawable_tower.setPosition(_position);


    // make the button as big as the image and so that text fits in side
    float tx = _drawable_tower.getGlobalBounds().getSize().x;
    float ty = _drawable_tower.getGlobalBounds().getSize().y;
    
    float text_size = _text.getCharacterSize();
    _button.setSize({tx, ty + text_size});
    _size = sf::Vector2f(tx, ty + text_size);

    // sets text couple pixels higher
    float buffer = 5;

    // TODO: fix text centering
    float text_x = _drawable_tower.getPosition().x + _button.getGlobalBounds().width / 2 ; - _text.getLocalBounds().width/2;
    std::cout << _text.getLocalBounds().width << std::endl;
    float text_y = _drawable_tower.getPosition().y + _drawable_tower.getGlobalBounds().height ; // - _text.getCharacterSize() - buffer;

    _text.setPosition({text_x, text_y});

}

void TowerDragButton::set_drag_flag(){
    _drag_flag = true;
}

void TowerDragButton::reset_drag_flag(){
    _drag_flag = false;
}

bool TowerDragButton::get_drag_flag() const{
    return _drag_flag;
}


void TowerDragButton::set_dragging_drawable_pos(sf::RenderWindow& window){
    // assumes mouse has clicked and flag is on
    float mouse_x = sf::Mouse::getPosition(window).x;
    float mouse_y = sf::Mouse::getPosition(window).y; 
    
    // float drag_pos_x = mouse_x - _dragging_tower_offset.x;
    // float drag_pos_y = mouse_y - _dragging_tower_offset.y;

    float drag_pos_x = mouse_x - _drawable_dragging_tower.getGlobalBounds().width/2;
    float drag_pos_y = mouse_y - _drawable_dragging_tower.getGlobalBounds().height/2;

    _drawable_dragging_tower.setPosition({drag_pos_x, drag_pos_y});

}

// call only once after mouse press obj button before drag_flag is set
void TowerDragButton::set_dragging_drawable_offset(sf::RenderWindow& window){

    
    if(this->is_mouse_over(window)){
        float mouse_x = sf::Mouse::getPosition(window).x;
        float mouse_y = sf::Mouse::getPosition(window).y;

        float button_x = _button.getPosition().x;
        float button_y = _button.getPosition().y;

    _dragging_tower_offset = sf::Vector2f(mouse_x - button_x, mouse_y - button_x);
    }
}

void TowerDragButton::handle_events(sf::RenderWindow& window, const sf::Event& event, Level& level){

     if(event.type == sf::Event::MouseButtonPressed){
                if(is_mouse_over(window) && !_drag_flag){
                    set_drag_flag();
                    set_dragging_drawable_offset(window);
                    set_dragging_drawable_pos(window);
                }
            }
    if(event.type == sf::Event::MouseMoved){
        if(get_drag_flag()){
            set_dragging_drawable_pos(window);
        }
    }

    if(event.type == sf::Event::MouseButtonReleased){
        if(get_drag_flag()){
            // TODO: Add functionality here
            reset_drag_flag();
        }
    }

}



void TowerDragButton::draw(sf::RenderTarget& target, sf::RenderStates) const {

    
    target.draw(_button);
    target.draw(_drawable_tower);
    target.draw(_text);

    if(_drag_flag){
        target.draw(_drawable_dragging_tower);
    }

}

