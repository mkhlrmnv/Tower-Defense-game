#include "tower_drag_button.hpp"
#include <iostream>

TowerDragButton::TowerDragButton(int type, sf::Vector2f position, sf::Color outline, sf::Color fill, ResourceHandler& rh): 

Button(rh.get_tower_name(type), {80, 130}, position, fill, outline, rh.get_font()), 
    _tower_type(type), 
    _drag_flag(false), 
    _rh(rh),
    _tower_price(0), 
    _button_enabled(true){
    
    _tower_price = _rh.get_tower_info(_tower_type, TowerAttributes::MONEY);

   
    setup_font();
    
    // TODO: set price and other attributes

    setup_tower_images();
    setup_button_texts();
    setup_attribute_images();
}


void TowerDragButton::setup_tower_images(){
    
    _button.setOutlineThickness(0);
    
    float og_img_size  = 32;
    // scale image to 80 pixels, and set scale negative for facing left
    float scale = _img_size / og_img_size;


    // set the first frame of the spreadsheet to represent tower and flip to face left
    _drawable_tower.setTexture(_rh.get_texture_tower(_tower_type));
    _drawable_tower.setTextureRect(sf::IntRect(0, 0, 32,32));
    _drawable_tower.setScale({-scale, scale});

    // center the image for horizontally (width - image_size)/2 = 
    float center_buffer = (80-60)/2;
    
    // reserve space for title
    float title_space = 20;

    float img_x = _position.x + center_buffer;
    float img_y = _position.y + title_space;
    
    // offset x with image size to correct position flip with negative scale
    _drawable_tower.setPosition({img_x + _img_size, img_y}); 

    _img_background.setPosition({img_x, img_y});
    auto sky_blue = sf::Color(195, 234, 252);

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

    // set image to middle of the mouse
    float drag_pos_x = mouse_x - _drawable_dragging_tower.getGlobalBounds().width/2 + _img_size;
    float drag_pos_y = mouse_y - _drawable_dragging_tower.getGlobalBounds().height/2;

    _drawable_dragging_tower.setPosition({drag_pos_x, drag_pos_y});

}


const sf::Sprite* TowerDragButton::get_dragging_image() const{

    // side draws the dragging image so that it is on top of every button.
    if(get_drag_flag()){
        return &_drawable_dragging_tower;
    }else{
        return nullptr;
    }
}

int TowerDragButton::get_type() const {
    return _tower_type;
}

void TowerDragButton::add_tower_to_release_square(sf::RenderWindow& window, Level& lv){
    if(inside_grid(_release_pos, lv) && (lv.get_cash()>=_tower_price)){

        auto square_ptr = lv.get_square_by_pos(window_coords_to_level_coords(_release_pos));
        bool tower_add_successful = lv.add_tower_by_type(_tower_type, window_coords_to_level_coords(_release_pos));
        if (tower_add_successful){
            lv.take_cash(_tower_price);
        }
    }
}

void TowerDragButton::update(int player_cash){
    if(player_cash < _tower_price){
        _button_enabled = false;
        _price_text.setFillColor(sf::Color::Red);
    }else{
        _price_text.setFillColor(sf::Color::White);
        _button_enabled = true;
    }
}


void TowerDragButton::handle_events(sf::RenderWindow& window, const sf::Event& event, Level& lv){

    if(_button_enabled){
        if(event.type == sf::Event::MouseButtonPressed){
                    if(is_mouse_over(window) && !_drag_flag){
                        set_drag_flag();
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
                reset_drag_flag();
                _release_pos = sf::Mouse::getPosition(window);
                auto idx = window_coords_to_grid_index(_release_pos, lv);
                add_tower_to_release_square(window, lv);
            }
        }

    }
     
}



void TowerDragButton::draw(sf::RenderTarget& target, sf::RenderStates states) const {

    target.draw(_button);
    target.draw(_img_background);
    target.draw(_drawable_tower);

    // texts
    target.draw(_text);
    target.draw(_price_text);
    target.draw(_hp_text);
    target.draw(_dmg_text);
    target.draw(_rng_text);
    target.draw(_atkspd_text);

    // attribute images

    target.draw(_hp_img);
    target.draw(_dmg_img);
    target.draw(_rng_img);
    target.draw(_atkspd_img);

}

