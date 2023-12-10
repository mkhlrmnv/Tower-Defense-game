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
    

    setup_tower_images();
    setup_button_texts();
    setup_attribute_images();
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

void TowerDragButton::add_tower_to_release_square(sf::RenderWindow& window, Level& lv){
    if(inside_grid(_release_pos, lv) && (lv.get_cash()>=_tower_price)){

        auto square_ptr = lv.get_square_by_pos(window_coords_to_level_coords(_release_pos));
        bool tower_add_successful = lv.add_tower_by_type(_tower_type, window_coords_to_level_coords(_release_pos));
        if (tower_add_successful){
            lv.take_cash(_tower_price);
        }
    }
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

    _img_background.setFillColor(sky_blue);
    _img_background.setOutlineThickness(2);
    _img_background.setOutlineColor(_button_outline_color);
    _img_background.setSize({_img_size, _img_size});
    
    // same for the dragging tower image

    _drawable_dragging_tower.setTexture(_rh.get_texture_tower(_tower_type));
    _drawable_dragging_tower.setTextureRect(sf::IntRect(0, 0, 32,32));
    _drawable_dragging_tower.setScale({-scale, scale});

    // position corrected in set_dragging_drawable_pos
}

void TowerDragButton::setup_button_texts(){
    
    auto brown = sf::Color(121, 85, 72);

    // tower name - use inherited button text
    auto pos = _button.getPosition();

   
    _text.setFillColor(brown);
    _text.setCharacterSize(12);

    float title_x = pos.x  + _button.getGlobalBounds().width / 2 - _text.getGlobalBounds().width / 2.f;
    float title_y = pos.y;

    // std::cout << "x"<<title_x << "" << title_y << std::endl; 

    //_text.setOrigin(_text.getGlobalBounds().getSize() / 2.f + _text.getGlobalBounds().getPosition());
    _text.setPosition({title_x, title_y});

    
    _price_text.setPosition({0,0});
    float price_char_size = 20; 
    
    
    _price_text.setCharacterSize(price_char_size);
    _price_text.setFillColor(sf::Color::White);
    _price_text.setOutlineColor(sf::Color::Black);
    _price_text.setOutlineThickness(1);
    _price_text.setString("$" + std::to_string(_tower_price));  

    _price_text.setOrigin(_price_text.getGlobalBounds().width / 2.f, _price_text.getGlobalBounds().height / 2.f);

    float price_x = _img_background.getPosition().x + _img_background.getGlobalBounds().width/2;
    float price_y = _img_background.getPosition().y + _img_background.getGlobalBounds().height - price_char_size;
    
    _price_text.setPosition({price_x, price_y});

    // modify these
    float start_x_offset = 4;
    float char_size = 12;
    float line_spacing = 10;
    float img_text_space = 2;

    float center_point = _img_background.getGlobalBounds().width/2;

    // assemble texts in 2x2 matrix

    float x_1 = start_x_offset + _button.getGlobalBounds().left + _attr_img_size + img_text_space;
    float y_1 = _drawable_tower.getGlobalBounds().top + _drawable_tower.getGlobalBounds().height + line_spacing;

    float x_2 =  _img_background.getPosition().x + center_point + _attr_img_size + img_text_space;
    float y_2 =  y_1 + char_size + line_spacing;


    // first column

    float hp_x = x_1;
    float hp_y = y_1;

    _hp_text.setCharacterSize(char_size);
    _hp_text.setFillColor(brown);
    _hp_text.setString(std::to_string(_rh.get_tower_info(_tower_type, TowerAttributes::HP)));
    _hp_text.setPosition({hp_x, hp_y});



    float dmg_x = x_1;
    float dmg_y = y_2;

    _dmg_text.setCharacterSize(char_size);
    _dmg_text.setFillColor(brown);
    _dmg_text.setString(std::to_string(_rh.get_tower_info(_tower_type, TowerAttributes::DMG))); 

    _dmg_text.setPosition({dmg_x, dmg_y});



    // second column

    float rng_x = x_2;
    float rng_y = y_1;

    _rng_text.setCharacterSize(char_size);
    _rng_text.setFillColor(brown);
    _rng_text.setString(std::to_string(_rh.get_tower_info(_tower_type, TowerAttributes::RNG)));

    _rng_text.setPosition({rng_x, rng_y});

    float atkspd_x = x_2;
    float atkspd_y = y_2;  

    _atkspd_text.setCharacterSize(char_size);
    _atkspd_text.setFillColor(brown);
    _atkspd_text.setString(std::to_string(_rh.get_tower_info(_tower_type, TowerAttributes::ATKSPD)));
    
    _atkspd_text.setPosition({atkspd_x, atkspd_y});
}

void TowerDragButton::setup_font(){
    _price_text.setFont(_rh.get_font());
    _hp_text.setFont(_rh.get_font());
    _dmg_text.setFont(_rh.get_font());
    _rng_text.setFont(_rh.get_font());
    _atkspd_text.setFont(_rh.get_font());

}

void TowerDragButton::setup_attribute_images(){


    // modify these

    float tweak_x = 0;
    float tweak_y = 2;

    float start_x_offset = 4;
    float char_size = 10;
    float line_spacing = 10;

    float center_point = _img_background.getGlobalBounds().width/2;

    // assemble images in 2x2 matrix

    float x_1 = tweak_x + start_x_offset + _button.getGlobalBounds().left ;
    float y_1 = tweak_y + _drawable_tower.getGlobalBounds().top + _drawable_tower.getGlobalBounds().height + line_spacing;

    float x_2 =  tweak_x + _img_background.getPosition().x + center_point;
    float y_2 =  y_1 + char_size + line_spacing;
    
    // first column
    float hp_x = x_1;
    float hp_y = y_1;

    setup_attribute_image(TowerAttributes::HP, _hp_img, {hp_x, hp_y});

    float dmg_x = x_1;
    float dmg_y = y_2;

    setup_attribute_image(TowerAttributes::DMG, _dmg_img, {dmg_x, dmg_y}); 

    // second column

    float rng_x = x_2;
    float rng_y = y_1;

    setup_attribute_image(TowerAttributes::RNG, _rng_img, {rng_x, rng_y});

    float atkspd_x = x_2;
    float atkspd_y = y_2;

    setup_attribute_image(TowerAttributes::ATKSPD, _atkspd_img, {atkspd_x, atkspd_y});



}

void TowerDragButton::setup_attribute_image(int type, sf::Sprite& sprite, sf::Vector2f pos ){
    
    sprite.setTexture(_rh.get_texture_attribute(type));
    sprite.setPosition(pos);

    float og_image_size = 16;
    float scale = _attr_img_size / og_image_size;
    sprite.setScale(scale, scale);
}


void TowerDragButton::draw(sf::RenderTarget& target, sf::RenderStates states) const {

    target.draw(_button);
    target.draw(_img_background);
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

