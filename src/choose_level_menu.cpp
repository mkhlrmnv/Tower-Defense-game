# include "choose_level_menu.hpp"



ChooseLevelMenu::ChooseLevelMenu(ResourceHandler& rh, Level& level): 
    _rh(rh), 
    _level(level),
    _level2_button(nullptr),
    _level3_button(nullptr),
    _level4_button(nullptr),
    _level5_button(nullptr),
    _level6_button(nullptr),
    _level_number(-1),
    _state(1),  
    _menu_enabled(true),
    _menu_background(){

        set_menu_background();
        set_buttons();
    }


void ChooseLevelMenu::disable_menu(){

    _menu_enabled = false;
}

void ChooseLevelMenu::enable_menu(){

    _menu_enabled = true;
}


int ChooseLevelMenu::get_state(){

    return _state;
}

void ChooseLevelMenu::reset(){

    _state = 1;
    _level_number = -1;

}


const std::string ChooseLevelMenu::get_level_to_load(){

    if(_level_number<1 || 6<_level_number){
        std::cout << "ChooseLevelMenu::get_level_to_load() : level selection has failed - no chosen level" << std::endl;
        return "";
    }else{
        return "../maps/map"+ std::to_string(_level_number) + ".txt";
    }  
        
}

void ChooseLevelMenu::handle_events(sf::RenderWindow& window, sf::Event& event){
    
    if(_menu_enabled){
        _level1_button->handle_events(window, event, _level);
        _level2_button->handle_events(window, event, _level);
        _level3_button->handle_events(window, event, _level);
        _level4_button->handle_events(window, event, _level);
        _level5_button->handle_events(window, event, _level);
        _level6_button->handle_events(window, event, _level);


        if(_level1_button->button_pressed()){
            _level_number = 1;
            _state = 2; 
            _level1_button->reset_button();
            

        }else if(_level2_button->button_pressed()){
            _level_number = 2;
            _state = 2; 
            _level2_button->reset_button();

        }else if(_level3_button->button_pressed()){
            _level_number = 3;
            _state = 2; 
            _level3_button->reset_button();

        }else if(_level4_button->button_pressed()){
            _level_number = 4;
            _state = 2; 
            _level4_button->reset_button();

        }else if(_level5_button->button_pressed()){
            _level_number = 5;
            _state = 2; 
            _level5_button->reset_button();

        }else if(_level6_button->button_pressed()){
            _level_number = 6;
            _state = 2; 
            _level6_button->reset_button();
        }

    }   
}


void ChooseLevelMenu::set_menu_background(){

    _menu_background.setTexture(_rh.get_texture_menu(1));
    _menu_background.setPosition(0,0);
}

void ChooseLevelMenu::set_buttons(){

    // draw transparent buttons on top of texture 
    // positions and size hand picked
    // When the mouse hovers on top of button, transparent color alpha value is raised.

    sf::Color transparent_white(255, 255, 255, 0);

    _level1_button = new Button("",{306.f-125.f, 325.f-158.f}, {125, 158}, transparent_white, sf::Color::Transparent, _rh.get_font());
    _level2_button = new Button("",{306.f-125.f, 325.f-158.f}, {459, 158}, transparent_white, sf::Color::Transparent, _rh.get_font());
    _level3_button = new Button("",{306.f-125.f, 325.f-158.f}, {791, 166}, transparent_white, sf::Color::Transparent, _rh.get_font());
    _level4_button = new Button("",{306.f-125.f, 325.f-158.f}, {127, 458}, transparent_white, sf::Color::Transparent, _rh.get_font());
    _level5_button = new Button("",{306.f-125.f, 325.f-158.f}, {459, 458}, transparent_white, sf::Color::Transparent, _rh.get_font());
    _level6_button = new Button("",{306.f-125.f, 325.f-158.f}, {790, 458}, transparent_white, sf::Color::Transparent, _rh.get_font());

}


void ChooseLevelMenu::draw(sf::RenderTarget& target, sf::RenderStates state) const {

    if(_menu_enabled){
        target.draw(_menu_background);
        target.draw(*_level1_button);
        target.draw(*_level2_button);
        target.draw(*_level3_button);
        target.draw(*_level4_button);
        target.draw(*_level5_button);
        target.draw(*_level6_button);   
    }
    
}