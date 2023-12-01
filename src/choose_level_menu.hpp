#ifndef TOWER_DEFENCE_SRC_CHOOSE_LEVEL_MENU
#define TOWER_DEFENCE_SRC_CHOOSE_LEVEL_MENU


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "level.hpp"
#include "resource_handler.hpp"
#include "button.hpp"

#include <iostream>


class ChooseLevelMenu : public sf::Drawable{
public:

    ChooseLevelMenu( ResourceHandler& rh, Level& level);
    ~ChooseLevelMenu(){ 
    delete _level1_button;
    delete _level2_button;
    delete _level3_button;
    delete _level4_button;
    delete _level5_button;
    delete _level6_button;
    }

    // stop update, handle_events, draw
    void disable_menu();
    int get_state();
    const std::string get_level_to_load();
    void handle_events(sf::RenderWindow& window, sf::Event& event);


private:

    void set_menu_background();
    void set_buttons();

    void draw(sf::RenderTarget& target, sf::RenderStates state) const;

    bool _menu_enabled;
    int _level_number;
    int _state;

    sf::Sprite _menu_background;

    Button* _level1_button;
    Button* _level2_button;
    Button* _level3_button;
    Button* _level4_button;
    Button* _level5_button;
    Button* _level6_button;

    ResourceHandler& _rh;
    Level& _level;


};


#endif