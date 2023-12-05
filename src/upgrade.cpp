#include "upgrade.hpp"

Upgrade:: Upgrade(float grid_resolution, ResourceHandler& rh, Level& level, int upgrade_cost): _upgrade_menu_enabled(false), _rh(rh), _level(level), _tower_to_upgrade(nullptr),
_upgrade_button(nullptr), _upgrade_cost(upgrade_cost){

    setup_menu();
    //setup_text_line(_hp_img, _hp_text, {100, 100}, sf::Color::White, TowerAttributes::HP, 20);
    //_upgrade_menu_enabled = true;
}

void Upgrade::setup_menu(){

    auto white = sf::Color::White;

    auto beige = sf::Color(255, 204, 128);
    auto light_brown = sf::Color(199, 140, 88);
    auto brown = sf::Color(121, 85, 72);
    
    auto light_grey = sf::Color(80, 90, 80, 200);
    auto dark_grey = sf::Color(70, 80, 70);

    float x = 0; 
    float y = 0;

    float size_x = 100; 
    float size_y = 160;

    _background.setPosition({x, y});
    _background.setSize({size_x, size_y});
    _background.setFillColor(light_grey);
    _background.setOutlineColor(dark_grey);
    _background.setOutlineThickness(2);

    // for centering texts and buttons
    float bg_width = _background.getGlobalBounds().width;

    float line_spacing = 5;
    int char_size = 15;

    float attrs_start_x = 5;
    float attrs_start_y = 5;

    _name_text.setFont(_rh.get_font());
    _name_text.setString("SOME TOWER");
    _name_text.setCharacterSize(char_size);
    _name_text.setFillColor(white);

    // center pos 
    _name_text.setPosition(attrs_start_x, attrs_start_y);
    float name_width = _name_text.getGlobalBounds().width;
    _name_text.setPosition(attrs_start_x + bg_width/2.f - name_width/2.f, attrs_start_y );



    setup_text_line(_hp_img, _hp_text, {attrs_start_x, attrs_start_y + 1*(line_spacing + char_size)}, white, TowerAttributes::HP, char_size );
    setup_text_line(_dmg_img, _dmg_text, { attrs_start_x, attrs_start_y + 2*(line_spacing + char_size)}, white, TowerAttributes::DMG, char_size );
    setup_text_line(_rng_img, _rng_text, { attrs_start_x, attrs_start_y + 3*(line_spacing + char_size)}, white, TowerAttributes::RNG, char_size );
    setup_text_line(_atkspd_img, _atkspd_text, { attrs_start_x, attrs_start_y + 4*(line_spacing + char_size)}, white, TowerAttributes::ATKSPD, char_size );

    _price_text.setFont(_rh.get_font());
    _price_text.setString("$" + std::to_string(_upgrade_cost));
    _price_text.setCharacterSize(char_size + 5);
    _price_text.setFillColor(sf::Color::White);
    _price_text.setPosition({x , attrs_start_y + 5*(line_spacing + char_size)});
    
    
    sf::Color green(0, 200, 0);
    float y_space_to_button = 10;

    _upgrade_button= new Button("UPGRADE", {80, 25}, {attrs_start_x, attrs_start_y + 6*(line_spacing + char_size) + y_space_to_button}, green, sf::Color::Black, _rh.get_font());
    _upgrade_button->center_text();
}

void Upgrade::setup_text_line(sf::Sprite& sprite, sf::Text &text, sf::Vector2f pos, sf::Color color, int attr_type, int char_size){

    float img_pos_y_tweak = 2;

    float img_size = 80;
    float scale = (char_size+1.f) / img_size;

    sprite.setTexture(_rh.get_texture_attribute(attr_type));
    sprite.setScale(scale, scale);

    sprite.setPosition(pos.x, pos.y + img_pos_y_tweak);

    float space_to_image_x = sprite.getGlobalBounds().width + 5;


    text.setFont(_rh.get_font());
    text.setString("1000");
    text.setCharacterSize(char_size);

    text.setPosition(pos.x + space_to_image_x, pos.y);

    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);

}


void Upgrade::set_menu(sf::Vector2f position){

    float x = position.x; 
    float y = position.y;
    
    // prevent menu popping half below the screen
    if(y > 800 - _background.getGlobalBounds().height /2.f){
        y = y -_background.getGlobalBounds().height / 2.f;
    }

    _background.setPosition(x, y);

    float line_spacing = 5;
    int char_size = 15; // dont change

    float attrs_start_x = x + 5;
    float attrs_start_y = y + 5;

   
    
    //std::string tower_name = "ARCHER";

    std::string tower_name = _rh.get_tower_name(_tower_to_upgrade->get_type());

    /*
    int hp = 1000; // _tower_to_upgrade->get_health()
    int dmg = 1000; // _tower_to_upgrade->get_damage()
    int rng = 1000; // _tower_to_upgrade->get_damage()
    int atkspd = 1000; // _tower_to_upgrade->get_damage()
    
    */

    int hp = _tower_to_upgrade->get_health();
    int dmg = _tower_to_upgrade->get_damage();
    int rng = _tower_to_upgrade->get_range();
    int atkspd = _tower_to_upgrade->get_attack_speed();

    
    // for centering texts and buttons
    float bg_width = _background.getGlobalBounds().width;

    _name_text.setString(tower_name);
    // center pos 
    _name_text.setPosition(attrs_start_x, attrs_start_y);
    float name_width = _name_text.getGlobalBounds().width;
    _name_text.setPosition(x + bg_width/2.f - name_width/2.f, attrs_start_y );



    set_text_line(_hp_img, _hp_text, {attrs_start_x, attrs_start_y + 1*(line_spacing + char_size)}, hp);
    set_text_line(_dmg_img, _dmg_text, { attrs_start_x, attrs_start_y + 2*(line_spacing + char_size)}, dmg);
    set_text_line(_rng_img, _rng_text, { attrs_start_x, attrs_start_y + 3*(line_spacing + char_size)}, rng);
    set_text_line(_atkspd_img, _atkspd_text, { attrs_start_x, attrs_start_y + 4*(line_spacing + char_size)}, atkspd);
    
    
    float price_width = _price_text.getGlobalBounds().width;
    
    _price_text.setPosition({x - price_width/2.f + bg_width/2.f, attrs_start_y + 5*(line_spacing + char_size)});

    float y_space_to_button = 5;

    _upgrade_button->set_position({x + bg_width/2.f - _upgrade_button->get_size().x/2.f, attrs_start_y + 6*(line_spacing + char_size) + y_space_to_button});
    _upgrade_button->center_text();
}   

void Upgrade::set_text_line(sf::Sprite& sprite, sf::Text &text, sf::Vector2f pos, int attr){
    
    float img_pos_y_tweak = 2;
    float space_to_image_x = sprite.getGlobalBounds().width + 5;

    sprite.setPosition(pos.x, pos.y + img_pos_y_tweak);
    text.setString(std::to_string(attr));
    text.setPosition(pos.x + space_to_image_x, pos.y);
}


void Upgrade::upgrade_tower(){
    if(_level.get_cash()>=_upgrade_cost){
        _tower_to_upgrade->level_up();
        _level.take_cash(_upgrade_cost);
    }
}

void Upgrade::grid_click(sf::Vector2i mouse_pos){
        
    // check if grid has tower
    Square* clicked_square = _level.get_square_by_pos(Button::window_coords_to_level_coords(mouse_pos));
    if(clicked_square->get_occupied() == occupied_type::tower){
        
        // determine what tower is in the square
        
        for(Tower* t_ptr: _level.get_towers()){
            if(_level.current_square(t_ptr) == clicked_square){
                _tower_to_upgrade = t_ptr;
            }
        }

        // if tower is found 
        if((_tower_to_upgrade)){
            
            auto pos = _tower_to_upgrade->get_position();
            _upgrade_menu_enabled = true;

            // pop menu in grid left of clicked grid
            // flip axes as coordintate change vector2D -> sf::vector2f 
            float x_pop = clicked_square->get_center().y + 40.f;
            float y_pop = clicked_square->get_center().x - 40.f;
            
            // set flag to disable other buttons and open menu;
            pop_upgrade_menu({x_pop, y_pop});
        }else{
            std::cout << "tower wasnt found in grid!" << std::endl;
        }
    }


}

bool Upgrade::outside_menu(sf::Vector2i mouse_pos){

    float m_x = mouse_pos.x;
    float m_y = mouse_pos.y;

    auto x_min = _background.getGlobalBounds().left;
    auto x_max = _background.getGlobalBounds().left + _background.getGlobalBounds().width;
    auto y_min = _background.getGlobalBounds().top;
    auto y_max = _background.getGlobalBounds().top + _background.getGlobalBounds().height;
    
    // the reverse of being inside boundaries
    return (!((x_min <  m_x) && (m_x < x_max) && (y_min <  m_y) && (m_y < y_max)));
}


bool Upgrade::inside_grid(sf::Vector2i mouse_pos){
    return Button::inside_grid(mouse_pos, _level);
}



void Upgrade::pop_upgrade_menu(sf::Vector2f pop_here){
    set_menu(pop_here);
    _upgrade_menu_enabled = true;
}

void Upgrade::close_upgrade_menu(){
    _upgrade_menu_enabled = false;
    _tower_to_upgrade = nullptr;
}



void Upgrade::handle_events(sf::RenderWindow& window, sf::Event& event){

    // menu on, tower to be upgraded selected

    if(_upgrade_menu_enabled){
        // mouse press inside button
        _upgrade_button->handle_events(window, event, _level);
        if(_upgrade_button->button_pressed()){
            upgrade_tower();
            _upgrade_button->reset_button();
            close_upgrade_menu();
        }
        // mouse press outside menu
        if(event.type ==sf::Event::MouseButtonPressed){
            auto mouse_pos = sf::Mouse::getPosition(window);
            if(outside_menu(mouse_pos)){

                close_upgrade_menu();
            }
        }

    // menu off 
    }else if(event.type == sf::Event::MouseButtonPressed){
            auto mouse_pos = sf::Mouse::getPosition(window);
            if(inside_grid(mouse_pos)){
                grid_click(mouse_pos);
            }
    }

}


void Upgrade::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    
    if(_upgrade_menu_enabled){

        target.draw(_background);

        target.draw(_hp_img);
        target.draw(_dmg_img);
        target.draw(_rng_img);
        target.draw(_atkspd_img);
        
        //target.draw(_upgrade_button_img);

        target.draw(_name_text);

        target.draw(_hp_text);
        target.draw(_dmg_text);
        target.draw(_rng_text);
        target.draw(_atkspd_text);

        target.draw(_price_text);

        target.draw(*_upgrade_button);
    }
    
}
