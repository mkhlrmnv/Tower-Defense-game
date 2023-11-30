#include "main_menu.hpp"



MainMenu::MainMenu(ResourceHandler& rh, Level& level):
_rh(rh), 
_level(level), 
_random_level_button(nullptr),
_choose_level_button(nullptr), 
_state(0), // GameState::MainMenu
_menu_enabled(true),
_menu_background(),
_menu_texture()

{
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

void MainMenu::disable_menu(){
    _menu_enabled = false;
}

int MainMenu::get_state(){
    return _state;
}

void MainMenu::handle_events(sf::RenderWindow& window, sf::Event& event){

    if(_menu_enabled){

        _choose_level_button->handle_events(window, event, _level);
        _random_level_button->handle_events(window, event, _level);

        // handle choose level button 
        if(_choose_level_button->button_pressed()){
            std::cout << "button 1 pressed " << std::endl;
            _state = 1; // ChooseLevelMenu
            _choose_level_button->reset_button();


        }
        // handle random level button 
        if(_random_level_button->button_pressed()){
            std::cout << "button 2 pressed " << std::endl;
            _state = 2; // Pause and load random map
            _random_level_button->reset_button();

        }

        // TODO: REMOVE
        if(event.type == sf::Event::MouseButtonPressed){
            auto pos = sf::Mouse::getPosition(window);
            std::cout << "x" << pos.x << std::endl;
            std::cout << "y" << pos.y << std::endl;
        }
    }

}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates state) const {
    if(_menu_enabled){
        target.draw(_menu_background);
        target.draw(*_choose_level_button);
        target.draw(*_random_level_button);
    }
   
}

