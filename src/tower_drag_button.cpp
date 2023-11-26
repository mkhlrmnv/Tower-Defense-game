#include "tower_drag_button.hpp"
#include <iostream>

TowerDragButton::TowerDragButton(int type, const std::string& name, sf::Vector2f position,  
sf::Texture obj_texture, sf::Color outline, sf::Color fill, std::array<int, 5>& tower_attrs, const sf::Font* font, ResourceHandler& rh): 

Button(name, {130, 180}, position, fill, outline, font), 
    _tower_type(type), 
    _texture(obj_texture), 
    _attributes(tower_attrs), 
    _drag_flag(false), 
    _tower_name(name),
    _rh(rh){

    // set the first frame of the spreadsheet to represent tower as 
    //_drawable_tower.setTextureRect(sf::IntRect(d(frame + animation_pos) * 32, 0 * 32, 32, 32));
    set_font();
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


    setup_button_texts();
    setup_attribute_images();
}




void TowerDragButton::setup_button_texts(){
    
    auto brown = sf::Color(121, 85, 72);

    // tower name - use inherited button text
    auto pos = _button.getPosition();

    float title_x = pos.x  + _button.getGlobalBounds().width / 2 - _text.getGlobalBounds().width / 2.f;
    float title_y = pos.y;

    std::cout << "x"<<title_x << "" << title_y << std::endl; 

    //_text.setOrigin(_text.getGlobalBounds().getSize() / 2.f + _text.getGlobalBounds().getPosition());
    _text.setPosition({title_x, title_y});


    std::cout << "_text.getGlobalBounds().height " << _text.getGlobalBounds().height << std::endl;
    std::cout << "_text.getGlobalBounds().width " << _text.getGlobalBounds().width << std::endl;
    std::cout << "_text.getGlobalBounds().left " << _text.getGlobalBounds().left << std::endl;
    std::cout << "_text.getGlobalBounds().top " << _text.getGlobalBounds().top << std::endl;

    _text.setFillColor(brown);
    _text.setCharacterSize(15);
    _text.setString(_tower_name);

    _price_text.setPosition({0,0});


    

    float price_char_size = 20; 
    
    

    _price_text.setCharacterSize(price_char_size);
    _price_text.setFillColor(sf::Color::White);
    _price_text.setOutlineColor(sf::Color::Black);
    _price_text.setOutlineThickness(1);
    _price_text.setString(std::to_string(_attributes.at(4))+"$");  

    _price_text.setOrigin(_price_text.getGlobalBounds().getSize() / 2.f);

    float price_x = _img_background.getPosition().x + _img_background.getGlobalBounds().width/2;
    float price_y = _img_background.getPosition().y + _img_background.getGlobalBounds().height - price_char_size;
    
    
    std::cout << "_price_text.getGlobalBounds().height " << _price_text.getGlobalBounds().height << std::endl;
    std::cout << "_price_text.getGlobalBounds().width " << _price_text.getGlobalBounds().width << std::endl;
    std::cout << "_price_text.getGlobalBounds().left " << _price_text.getGlobalBounds().left << std::endl;
    std::cout << "_price_text.getGlobalBounds().top " << _price_text.getGlobalBounds().top << std::endl;    

    
    _price_text.setPosition({price_x, price_y});


    

    // modify these
    float char_size = 18;
    float line_spacing = 2;
    float center_point = _img_background.getGlobalBounds().width/2;
    float attr_start_x = _img_background.getPosition().x + center_point;
    float attr_start_y = _img_background.getPosition().y +_drawable_tower.getGlobalBounds().height;

    float hp_x = attr_start_x;
    float hp_y = attr_start_y;

    _hp_text.setCharacterSize(char_size);
    _hp_text.setFillColor(brown);
    _hp_text.setString(std::to_string(_attributes.at(0)));

    _hp_text.setPosition({hp_x, hp_y});

    float dmg_x = attr_start_x;
    float dmg_y = hp_y + char_size + line_spacing;

    _dmg_text.setCharacterSize(char_size);
    _dmg_text.setFillColor(brown);
    _dmg_text.setString(std::to_string(_attributes.at(1))); 

    _dmg_text.setPosition({dmg_x, dmg_y});

    float rng_x = attr_start_x ;
    float rng_y = dmg_y + char_size + line_spacing;

    _rng_text.setCharacterSize(char_size);
    _rng_text.setFillColor(brown);
    _rng_text.setString(std::to_string(_attributes.at(2)));

    _rng_text.setPosition({rng_x, rng_y});

    float atkspd_x = attr_start_x ;
    float atkspd_y = rng_y + char_size + line_spacing;  

    _atkspd_text.setCharacterSize(char_size);
    _atkspd_text.setFillColor(brown);
    _atkspd_text.setString(std::to_string(_attributes.at(3)));
    
    _atkspd_text.setPosition({atkspd_x, atkspd_y});
}

void TowerDragButton::set_font(){
    _price_text.setFont(*_font);
    _hp_text.setFont(*_font);
    _dmg_text.setFont(*_font);
    _rng_text.setFont(*_font);
    _atkspd_text.setFont(*_font);


}

void TowerDragButton::setup_attribute_images(){

    float start_y_offset = 5;
    float start_x_offset = 20;
    float img_size = 15;
    float line_spacing = 5;

    float attr_start_x = _img_background.getPosition().x + start_x_offset;
    float attr_start_y = _img_background.getPosition().y +_drawable_tower.getGlobalBounds().height;

    float hp_x = attr_start_x ;
    float hp_y = attr_start_y + start_y_offset ;

    set_attribute_image(TowerAttributes::HP, _hp_img, {hp_x, hp_y});

    float dmg_x = attr_start_x;
    float dmg_y = hp_y + img_size + line_spacing;

    set_attribute_image(TowerAttributes::RNG, _dmg_img, {dmg_x, dmg_y}); // TODO: get image 

    float rng_x = attr_start_x;
    float rng_y = dmg_y + img_size + line_spacing;

    set_attribute_image(TowerAttributes::RNG, _rng_img, {rng_x, rng_y});

    float atkspd_x = attr_start_x;
    float atkspd_y = rng_y + img_size + line_spacing;

    set_attribute_image(TowerAttributes::ATKSPD, _atkspd_img, {atkspd_x, atkspd_y});



}

void TowerDragButton::set_attribute_image(int type, sf::Sprite& sprite, sf::Vector2f pos ){
    
    sprite.setTexture(_rh.get_texture_attribute(type));
    sprite.setPosition(pos);

    float image_size = 80;
    float scale = 16 / image_size;
    sprite.setScale(scale, scale);
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




    // Draw in side menu instead so dragging image appears at top of everything
    /* 
    if(_drag_flag){
        target.draw(_drawable_dragging_tower);
    }*/
}

