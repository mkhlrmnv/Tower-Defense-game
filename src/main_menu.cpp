#include "main_menu.hpp"



MainMenu::MainMenu(ResourceHandler& rh, Level& level):_rh(rh), _level(level), _random_level_button(nullptr), _choose_level_button(nullptr), _next_state(-1){
    set_menu_background();
    set_buttons();
}

void MainMenu::set_menu_background(){
    if(!_menu_texture.loadFromFile("../assets/textures/Menu/Start_Menu_1.png")){
        std::cout << "menu 1 load failed" << std::endl;
    }
    _menu_background.setTexture(_menu_texture);
    _menu_background.setPosition(0,0);
}

void MainMenu::set_buttons(){
    
    // draw transparent buttons on top of texture 
    // positions and size hand picked
    // When the mouse hovers on top of button button 

    sf::Color transparent_beige(255, 204, 128, 0);


    _choose_level_button = new Button("",{699.f-391.f, 517.f-374.f}, {391, 374}, transparent_beige, sf::Color::Transparent, _rh.get_font());
    _random_level_button = new Button("",{699.f-391.f, 517.f-374.f}, {391, 586}, transparent_beige, sf::Color::Transparent, _rh.get_font());

}


void MainMenu::handle_events(sf::RenderWindow& window, sf::Event& event){

    _choose_level_button->handle_events(window, event, _level);
    _random_level_button->handle_events(window, event, _level);


    // handle choose level button 
    if(_choose_level_button->button_pressed()){
        std::cout << "button 1 pressed " << std::endl;
        _choose_level_button->reset_button();
    }

    if(_random_level_button->button_pressed()){
        std::cout << "button 2 pressed " << std::endl;
        _random_level_button->reset_button();
    }

    if(event.type == sf::Event::MouseButtonPressed){
        auto pos = sf::Mouse::getPosition(window);
        std::cout << "x" << pos.x << std::endl;
        std::cout << "y" << pos.y << std::endl;
    }

}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates state) const {
    target.draw(_menu_background);
    target.draw(*_choose_level_button);
    target.draw(*_random_level_button);
}

