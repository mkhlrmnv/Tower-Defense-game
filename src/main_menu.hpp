#ifndef TOWER_DEFENCE_SRC_MAINMENU
#define TOWER_DEFENCE_SRC_MAINMENU

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "level.hpp"
#include "resource_handler.hpp"
#include "button.hpp"

#include <iostream>
#include <memory>


class MainMenu : public sf::Drawable{
public:

    MainMenu( ResourceHandler& rh, Level& level);
    ~MainMenu(){ delete _choose_level_button; delete _random_level_button;}


    // stop update, handle_events, draw
    void end_menu();
    void get_next_state();

    void handle_events(sf::RenderWindow& window, sf::Event& event);


private:

    void set_menu_background();
    void set_buttons();

    void draw(sf::RenderTarget& target, sf::RenderStates state) const;

    int _next_state;

    sf::Sprite _menu_background;
    sf::Texture _menu_texture;

    Button* _random_level_button;
    Button* _choose_level_button;

    ResourceHandler& _rh;
    Level& _level;


};



#endif