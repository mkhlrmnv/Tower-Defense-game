#ifndef TOWER_DEFENCE_SRC_MAINMENU
#define TOWER_DEFENCE_SRC_MAINMENU

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "level.hpp"
#include "resource_handler.hpp"
#include "button.hpp"

#include "iostream"


class MainMenu : public sf::Drawable{
public:

    void proceed_to_game();
    void proceed_to_level_menu();

    void handle_events(sf::RenderWindow& window, sf::Event& event);


private:

    void draw(sf::RenderTarget& target, sf::RenderStates state);

sf::Sprite _menu_image;

Button _random_level_button;
Button _choose_level_button;

ResourceHandler _rh;
Level _level;


};



#endif