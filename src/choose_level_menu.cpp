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
    _state(1), // GameState::LevelMenu 
    _menu_enabled(true),
    _menu_background(),
    _menu_texture(){

        set_menu_background();
        set_buttons();
    }



void ChooseLevelMenu::set_menu_background(){

    if(!_menu_texture.loadFromFile("../assets/textures/Menu/Start_Menu_2.png")){
        std::cout << "choose level menu load failed" << std::endl;
    }
    _menu_background.setTexture(_menu_texture);
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

int ChooseLevelMenu::get_state(){
    return _state;
}

void ChooseLevelMenu::disable_menu(){
    _menu_enabled = false;
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
            std::cout << "button 1 pressed " << std::endl;
            _level_number = 1;
            _state = 2; 
            _level1_button->reset_button();
            

        }else if(_level2_button->button_pressed()){
            std::cout << "button 2 pressed " << std::endl;
            _level_number = 2;
            _state = 2; 
            _level2_button->reset_button();

        }else if(_level3_button->button_pressed()){
            std::cout << "button 3 pressed " << std::endl;
            _level_number = 3;
            _state = 2; 
            _level3_button->reset_button();

        }else if(_level4_button->button_pressed()){
            std::cout << "button 4 pressed " << std::endl;
            _level_number = 4;
            _state = 2; 
            _level4_button->reset_button();

        }else if(_level5_button->button_pressed()){
            std::cout << "button 5 pressed " << std::endl;
            _level_number = 5;
            _state = 2; 
            _level5_button->reset_button();

        }else if(_level6_button->button_pressed()){
            std::cout << "button 6 pressed " << std::endl;
            _level_number = 6;
            _state = 2; 
            _level6_button->reset_button();
        }

        // TODO: REMOVE
        if(event.type == sf::Event::MouseButtonPressed){
            auto pos = sf::Mouse::getPosition(window);
            std::cout << "x" << pos.x << std::endl;
            std::cout << "y" << pos.y << std::endl;
        }

    }   
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