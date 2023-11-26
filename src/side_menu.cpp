#include <side_menu.hpp>


SideMenu::SideMenu(float game_resolution, float side_menu_width, ResourceHandler& rh, Level& level) :
 _game_resolution(game_resolution), _side_menu_width(side_menu_width), _level(level), _rh(rh), _fill_color(), _outline_color(), _drag_img_ptrs({}){
    
    
    auto beige = sf::Color(255, 204, 128);
    auto light_brown = sf::Color(199, 140, 88);
    auto brown = sf::Color(121, 85, 72);

    _outline_color = light_brown;
    _fill_color = beige;

    
    setup_background();
    setup_info_displays();
    setup_drag_buttons();
    setup_round_button();
    setup_menu_title();
}

void SideMenu::setup_background(){
        
    _background.setPosition({_game_resolution, 0});
    _background.setSize({_side_menu_width, _game_resolution});
    _background.setFillColor(_fill_color);
    _background.setOutlineColor(_outline_color);

    // set outline inwards
    _background.setOutlineThickness(-2);
}

void SideMenu::setup_menu_title(){

    auto brown = sf::Color(121, 85, 72);

    std::string title_text = "Drag Towers to grid!";
    
    float buffer_x = 5;
    float buffer_y = 20;

    float x = _background.getPosition().x;
    float y = _background.getPosition().y;
    
    _title.setFont(_rh.get_font());
    _title.setString(title_text);
    _title.setCharacterSize(25);
    _title.setFillColor(brown);
    _title.setPosition({x + buffer_x, y + buffer_y});

}

void SideMenu::setup_drag_buttons(){

    float x_wrt_bg  = 10;
    float y_wrt_bg  = 100;

    float x1 = x_wrt_bg  + _background.getPosition().x; 
    float y1 = y_wrt_bg + _background.getPosition().y;

    sf::Color ashgrey(178, 190, 181); 
    
    // iterates trough tower types and creates buttons accordingly
    for(int i = 0; i<6; i++){

        auto tower_name = _rh.get_tower_name(i);
        auto tower_texture = _rh.get_texture_tower(i);
        auto attrs = _rh.get_tower_info(i);
       

        _drag_buttons.push_back(new TowerDragButton(i, _rh.get_tower_name(i), {x1 +(130+20)*(i%2), y1 + (180 + 20)*(i%3)}, _rh.get_texture_tower(i), _outline_color, _fill_color, _rh.get_tower_info(i), &_rh.get_font(), _rh));
    }   

}

void SideMenu::setup_round_button(){

    // get position of the last button 

   _round_button =  new Button("IMPLEMENT FUNCTIONALITY", {280, 50}, {810, 700}, sf::Color::Red, sf::Color::White, &_rh.get_font());
   _round_button->center_text();

}

void SideMenu::setup_info_display(int type, sf::Sprite& sprite, sf::Text& text_obj, sf::Vector2f pos, float char_size){

    auto brown = sf::Color(121, 85, 72);
    auto color = brown;
    
    float image_size = 80;
    float scale = 30 / image_size;
    sprite.setTexture(_rh.get_texture_attribute(type));
    sprite.setPosition(pos);
    auto s = sprite.getScale();
        std::cout <<"scale x"<< s.x << "scale y" << s.y << std::endl;


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

    float side_menu_width = _background.getGlobalBounds().width;
    float side_menu_height = _background.getGlobalBounds().height;

    
    int info_display_height = char_size;
    int info_display_width = side_menu_width / 3;

    float display_start_x = _background.getGlobalBounds().left + buffer;
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

    setup_info_display(TowerAttributes::ATKSPD, _round_count_drawable, _round_count_text, {r_x + extra_space, r_y}, char_size); // TODO: image for rounds? 

}

/* 
void SideMenu::setup_info_displays(){
    
    sf::Color ashgrey(178, 190, 181); 
    auto text_color = ashgrey;

    // raise the displays from the bottom some pixels
    float buffer = 5; 
    float char_size = 30;

    float display_start_x = _background.getGlobalBounds().left;
    float side_menu_width = _background.getGlobalBounds().width;
    float side_menu_height = _background.getGlobalBounds().height;

    
    int info_display_height = char_size;
    int info_display_width = side_menu_width / 3;

    int cash_x = display_start_x;
    int cash_y = side_menu_height - info_display_height - buffer;

    _cash_text.setPosition(sf::Vector2f(cash_x, cash_y));
    _cash_text.setFillColor(text_color);
    _cash_text.setCharacterSize(char_size);

    int lives_x = cash_x + info_display_width;
    int lives_y = side_menu_height - info_display_height - buffer;

    _lives_text.setPosition(sf::Vector2f(lives_x, lives_y));
    _lives_text.setFillColor(text_color);
    _lives_text.setCharacterSize(char_size);

    int round_count_x = lives_x + info_display_width;
    int round_count_y = side_menu_height - info_display_height - buffer;

    _round_count_text.setPosition(sf::Vector2f(round_count_x, round_count_y));
    _round_count_text.setFillColor(text_color);
    _round_count_text.setCharacterSize(char_size);

}*/



void SideMenu::draw( sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_background);
    target.draw(_cash_text);
    target.draw(_lives_text);
    target.draw(_round_count_text);

    target.draw(_title);
    target.draw(*_round_button);

    if(nullptr == _lives_drawable.getTexture()){
        std::cout <<"no texture"<< std::endl;
    }
    //std::cout <<"x"<<  _lives_drawable.getPosition().x << "y" << _lives_drawable.getPosition().y << std::endl;
    //std::cout <<"w"<<  _lives_drawable.getGlobalBounds().width << "h" << _lives_drawable.getGlobalBounds().height << std::endl;


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
    for(auto drag_button : _drag_buttons){
        drag_button->handle_events(window, event, _level);
        //std::cout <<"type:" << drag_button->get_type() << " dragging: " << drag_button->get_drag_flag() << std::endl; ;
        _drag_img_ptrs[drag_button->get_type()] =  drag_button->get_dragging_image();
    }
    _round_button->handle_events(window, event, _level);
}

void SideMenu::update(){

    std::string cash = std::to_string(_level.get_cash());
    std::string lives = std::to_string(_level.get_lives());
    std::string round_count = std::to_string(_level.get_round());

    _cash_text.setString(cash);
    _lives_text.setString(lives);
    _round_count_text.setString(round_count);

}