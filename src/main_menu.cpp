#include "main_menu.hpp"



MainMenu::MainMenu(ResourceHandler& rh, Level& level):
_rh(rh), 
_level(level), 
_random_level_button(nullptr),
_choose_level_button(nullptr), 
_state(0), // GameState::MainMenu
_menu_enabled(true),
_menu_background(){
    
    set_menu_background();
    set_buttons();
}

void MainMenu::disable_menu(){

    _menu_enabled = false;
}

void MainMenu::enable_menu(){

    _menu_enabled = true;
}

int MainMenu::get_state(){

    return _state;
}

void MainMenu::reset(){

    _state = 0;
}

void MainMenu::handle_events(sf::RenderWindow& window, sf::Event& event){

    if(_menu_enabled){

        _choose_level_button->handle_events(window, event, _level);
        _random_level_button->handle_events(window, event, _level);

        // handle choose level button 
        if(_choose_level_button->button_pressed()){
            _state = 1; // ChooseLevelMenu
            _choose_level_button->reset_button();


        }
        // handle random level button 
        if(_random_level_button->button_pressed()){
            _state = 2; // Pause and load random map
            _random_level_button->reset_button();

        }
    }
}

void MainMenu::set_menu_background(){
    
    _menu_background.setTexture(_rh.get_texture_menu(0));
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

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates state) const {

    if(_menu_enabled){
        target.draw(_menu_background);
        target.draw(*_choose_level_button);
        target.draw(*_random_level_button);
    }
}

