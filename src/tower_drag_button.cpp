#include "tower_drag_button.hpp"
#include <iostream>

TowerDragButton::TowerDragButton(int type, const std::string name, sf::Vector2f position,  sf::Texture obj_texture, sf::Color outline, sf::Color fill, const std::array<int, 5>& tower_atrs) : 

Button(name, {130, 180}, position, fill, outline), _tower_type(type), _texture(obj_texture), _attributes(tower_atrs), _drag_flag(false){

    // set the first frame of the spreadsheet to represent tower as 
    //_drawable_tower.setTextureRect(sf::IntRect((frame + animation_pos) * 32, 0 * 32, 32, 32));

    
    _button.setOutlineThickness(2);


    float image_size = 32;

    // scale image to 80 pixels, and set scale negative for facing left
    float scale = 80 / image_size; 

    _drawable_tower.setTexture(_texture);
    _drawable_tower.setTextureRect(sf::IntRect(0, 0, 32,32));
    _drawable_tower.setScale({-scale, scale});

    // center the image for horizontally (width - image_size)/2 = 
    float center_buffer = (130 - 80)/2;
    
    // reserve space for title
    float title_space = 20;

    float img_x = position.x + center_buffer;
    float img_y = position.y + title_space;

    _drawable_tower.setPosition({img_x + _flip_correction, img_y}); 

    _img_background.setPosition({img_x, img_y});
    auto sky_blue = sf::Color(195, 234, 252);

    _img_background.setFillColor(sky_blue);
    _img_background.setOutlineThickness(2);
    _img_background.setOutlineColor(_button_outline_color);
    _img_background.setSize({80, 80});
    


    // same for the dragging tower image

    _drawable_dragging_tower.setTexture(_texture);
    _drawable_dragging_tower.setTextureRect(sf::IntRect(0, 0, 32,32));
    _drawable_dragging_tower.setScale({-scale, scale});


    // TODO: set price and other attributes
    /* 
    float text_size = _text.getCharacterSize();
    _button.setSize({tx, ty + text_size});
    _size = sf::Vector2f(tx, ty + text_size);

    float buffer = 5;

    float text_x = _drawable_tower.getPosition().x + _button.getGlobalBounds().width / 2 ; - _text.getLocalBounds().width/2;
    float text_y = _drawable_tower.getPosition().y + _drawable_tower.getGlobalBounds().height ; // - _text.getCharacterSize() - buffer;

    _text.setPosition({text_x, text_y});
    
    */
    

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

    // set image to middle of the mouse
    float drag_pos_x = mouse_x - _drawable_dragging_tower.getGlobalBounds().width/2 + _flip_correction;
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

const sf::Sprite* TowerDragButton::get_dragging_image() const{

    if(get_drag_flag()){
        return &_drawable_dragging_tower;
    }else{
        return nullptr;
    }
}

int TowerDragButton::get_type() const {
    return _tower_type;
}


void TowerDragButton::some_action_from_level(sf::RenderWindow& window, Level& lv){
    if(inside_grid(_release_pos, lv) && (lv.get_cash()>=_tower_price)){
        bool tower_add_successfull = lv.add_tower_by_type(_tower_type, window_coords_to_level_coords(_release_pos));
        lv.take_cash(_tower_price);
    }
}



void TowerDragButton::handle_events(sf::RenderWindow& window, const sf::Event& event, Level& lv){

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
            _release_pos = sf::Mouse::getPosition(window);
            auto idx = window_coords_to_grid_index(_release_pos, lv);
            //some_action_from_level(lv);
        }
    }

}



void TowerDragButton::draw(sf::RenderTarget& target, sf::RenderStates) const {

    
    target.draw(_button);
    target.draw(_img_background);
    target.draw(_drawable_tower);
    target.draw(_text);
}

