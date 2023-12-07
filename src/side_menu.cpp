#include <side_menu.hpp>


SideMenu::SideMenu(float game_resolution, float side_menu_width, ResourceHandler& rh, Level& level) :
    _game_resolution(game_resolution),
    _side_menu_width(side_menu_width),
    _level(level),
    _rh(rh),
    _fill_color(),
    _outline_color(),
    _drag_img_ptrs({}),
    _disable_buttons(false),
    _state(2) // pause
    {
    
    
    auto beige = sf::Color(255, 204, 128);
    auto light_brown = sf::Color(199, 140, 88);
    auto brown = sf::Color(121, 85, 72);

    _outline_color = light_brown;
    _fill_color = beige;

    setup_background();
    setup_info_displays();
    setup_drag_buttons();
    setup_round_button();
    //setup_menu_title();
}

void SideMenu::disable_buttons(){
    _disable_buttons = true; 
}

void SideMenu::enable_buttons(){
    _disable_buttons = false;
}


void SideMenu::setup_background(){
    _background_img.setTexture(_rh.get_texture_menu(2));
    _background_img.setPosition({_game_resolution, 0});
}


void SideMenu::setup_drag_buttons(){

    float x_wrt_bg  = 35;
    float y_wrt_bg  = 125;

    float x1 = x_wrt_bg  + _background_img.getPosition().x; 
    float y1 = y_wrt_bg + _background_img.getPosition().y;

    sf::Color ashgrey(178, 190, 181); 
    
    // iterates trough tower types and creates buttons accordingly
    for(int i = 0; i<6; i++){

        _drag_buttons.push_back(new TowerDragButton(i, {x1 +(130+20)*(i%2), y1 + (193)*(i%3)}, _outline_color, _fill_color, _rh));
    }   

}

void SideMenu::setup_round_button(){

    // get position of the last button 
    sf::Color red(220,0,0);
   _round_button =  new Button("start round", {280, 50}, {810, 700}, red, sf::Color::White, _rh.get_font());
   _round_button->center_text();

}

void SideMenu::setup_info_display(int type, sf::Sprite& sprite, sf::Text& text_obj, sf::Vector2f pos, float char_size){

    auto brown = sf::Color(121, 85, 72);
    auto color = brown;
    
    float image_size = 16;
    float scale = 30 / image_size;
    sprite.setTexture(_rh.get_texture_attribute(type));
    sprite.setPosition(pos);
    sprite.setScale(scale, scale);
    

    text_obj.setFont(_rh.get_font());
    text_obj.setCharacterSize(char_size);
    text_obj.setFillColor(sf::Color::White);
    text_obj.setOutlineThickness(2);
    text_obj.setOutlineColor(brown);
    
    auto img_size = sprite.getGlobalBounds();
    auto img_pos = sprite.getPosition();
    float gap_to_image = 5;
    float y_offset_to_image = 5;

    text_obj.setPosition( img_pos.x + img_size.width + gap_to_image, img_pos.y - y_offset_to_image);

}

void SideMenu::setup_info_displays(){


    float buffer = 5; 
    float char_size = 30;

    float side_menu_width = _background_img.getGlobalBounds().width;
    float side_menu_height = _background_img.getGlobalBounds().height;

    
    int info_display_height = char_size;
    int info_display_width = side_menu_width / 3;

    float display_start_x = _background_img.getGlobalBounds().left + buffer;
    float display_start_y =  side_menu_height - info_display_height - buffer;

    float l_x = display_start_x;
    float l_y = display_start_y;

    setup_info_display(TowerAttributes::HP, _lives_drawable, _lives_text, {l_x, l_y}, char_size);

    float c_x =  l_x + info_display_width;
    float c_y =  display_start_y;

    setup_info_display(TowerAttributes::MONEY, _cash_drawable, _cash_text, {c_x, c_y}, char_size);

    float r_x =  c_x + info_display_width;
    float r_y =  display_start_y;

    float extra_space = 10;

    setup_info_display(TowerAttributes::ROUND, _round_count_drawable, _round_count_text, {r_x + extra_space, r_y}, char_size);

}

int SideMenu::get_state(){
    return _state;
}

void SideMenu::pause(){
    _state = 2;
}


void SideMenu::draw( sf::RenderTarget& target, sf::RenderStates states) const{

    target.draw(_background_img);
    target.draw(_cash_text);
    target.draw(_lives_text);
    target.draw(_round_count_text);

    target.draw(*_round_button);
    target.draw(_lives_drawable);
    target.draw(_cash_drawable);
    target.draw(_round_count_drawable);

    for (auto drag_button: _drag_buttons){ 
        target.draw(*drag_button);
    }
    for (auto drag_img_ptr : _drag_img_ptrs){
        if(drag_img_ptr){
            target.draw(*(drag_img_ptr));
        }
    }
}


void SideMenu::handle_events(sf::RenderWindow& window, const sf::Event& event){

    if(!_disable_buttons){

        for(auto drag_button : _drag_buttons){

            drag_button->handle_events(window, event, _level);
            _drag_img_ptrs[drag_button->get_type()] =  drag_button->get_dragging_image();
        }

        _round_button->handle_events(window, event, _level);

        if(_round_button->button_pressed()){
            // set state to running
            _state = 3;
            _round_button->reset_button();
        }
    }
}
    

void SideMenu::update(){

    std::string cash = std::to_string(_level.get_cash());
    std::string lives = std::to_string(_level.get_lives());
    std::string round_count = std::to_string(_level.get_round());

    _cash_text.setString(cash);
    _lives_text.setString(lives);
    _round_count_text.setString(round_count);

    for(auto button : _drag_buttons){
        button->update(_level.get_cash());
    }

}