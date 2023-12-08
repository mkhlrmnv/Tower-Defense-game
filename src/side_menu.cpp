#include <side_menu.hpp>


SideMenu::SideMenu(float game_resolution, float side_menu_width, ResourceHandler& rh, Level& level) :
 _game_resolution(game_resolution), _side_menu_width(side_menu_width), _level(level), _rh(rh){
    

    setup_background();
    setup_info_displays();
    setup_buttons();
    setup_menu_title();
}

void SideMenu::setup_background(){
    
    sf::Color charcoal(54, 69, 79);
    sf::Color ashgrey(178, 190, 181); 
    
    
    _background.setPosition({_game_resolution, 0});
    _background.setSize({_side_menu_width, _game_resolution});
    _background.setFillColor(charcoal);
    _background.setOutlineColor(ashgrey);

    // set outline inwards
    _background.setOutlineThickness(-2);
}

void SideMenu::setup_menu_title(){

    sf::Color ashgrey(178, 190, 181); 

    std::string title_text = "Drag towers to grids";
    
    float buffer_x = 5;
    float buffer_y = 20;

    float x = _background.getPosition().x;
    float y = _background.getPosition().y;
    
    _title.setFont(_rh.get_font());
    _title.setString(title_text);
    _title.setCharacterSize(30);
    _title.setFillColor(ashgrey);
    _title.setPosition({x + buffer_x, y + buffer_y});

}

void SideMenu::setup_buttons(){

    float x_wrt_bg  = 10;
    float y_wrt_bg  = 100;

    float x1 = x_wrt_bg  + _background.getPosition().x; 
    float y1 = y_wrt_bg + _background.getPosition().y;

    sf::Color ashgrey(178, 190, 181); 


    
    _drag_buttons.push_back(new TowerDragButton("$200", {80,80}, {x1,y1}, sf::Color::Black, _rh.get_texture_tower(ObjectTypes::ArcherTower), 1));
    _drag_buttons.at(0)->set_font(_rh.get_font());
    _drag_buttons.at(0)->set_color(ashgrey);

}


void SideMenu::setup_info_displays(){

    
    sf::Color ashgrey(178, 190, 181); 
    auto text_color = ashgrey;

    // raise the displays from the bottom some pixels
    float buffer = 5; 

    float display_start_x = _background.getGlobalBounds().left;
    float side_menu_width = _background.getGlobalBounds().width;
    float side_menu_height = _background.getGlobalBounds().height;

    _cash_text.setFont(_rh.get_font());
    _lives_text.setFont(_rh.get_font());
    _round_count_text.setFont(_rh.get_font());
    
    int info_display_height = 20;
    int info_display_width = side_menu_width / 3;

    int cash_x = display_start_x;
    int cash_y = side_menu_height - info_display_height - buffer;

    _cash_text.setPosition(sf::Vector2f(cash_x, cash_y));
    _cash_text.setFillColor(text_color);
    _cash_text.setCharacterSize(20);

    int lives_x = cash_x + info_display_width;
    int lives_y = side_menu_height - info_display_height - buffer;

    _lives_text.setPosition(sf::Vector2f(lives_x, lives_y));
    _lives_text.setFillColor(text_color);
    _lives_text.setCharacterSize(20);

    int round_count_x = lives_x + info_display_width;
    int round_count_y = side_menu_height - info_display_height - buffer;

    _round_count_text.setPosition(sf::Vector2f(round_count_x, round_count_y));
    _round_count_text.setFillColor(text_color);
    _round_count_text.setCharacterSize(20);

}



void SideMenu::draw( sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_background);
    target.draw(_cash_text);
    target.draw(_lives_text);
    target.draw(_round_count_text);
    target.draw(_title);
    for (auto drag_button: _drag_buttons){ 
        target.draw(*drag_button);
    }
}


void SideMenu::handle_events(sf::RenderWindow& window, const sf::Event& event){
    for(auto drag_button : _drag_buttons){
        drag_button->handle_events(window, event, _level);
    }
}

void SideMenu::update_displays(){

    std::string cash = "$" + std::to_string(_level.get_cash());
    std::string lives = "Lives: " + std::to_string(_level.get_lives());
    std::string round_count = "Round: " + std::to_string(_level.get_round());


    _cash_text.setString(cash);
    _lives_text.setString(lives);
    _round_count_text.setString(round_count);

}