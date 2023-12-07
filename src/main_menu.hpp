#ifndef TOWER_DEFENCE_SRC_MAINMENU
#define TOWER_DEFENCE_SRC_MAINMENU

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "level.hpp"
#include "resource_handler.hpp"
#include "button.hpp"

#include <iostream>
#include <memory>


/**
 * @brief A class representing the start menu / main menu of the game. 
 * @param ResourceHandler&
 * @param Level&
 */
class MainMenu : public sf::Drawable{
public:

    MainMenu( ResourceHandler& rh, Level& level);
    ~MainMenu(){ delete _choose_level_button; delete _random_level_button;}
    MainMenu(const MainMenu&) = delete; 
    MainMenu& operator=(const MainMenu&) = delete;
    
    /**
     * @brief disable menu when the GameState is not MainMenu
     * 
     */
    void disable_menu();

    /**
     * @brief enable menu when the GameState is MainMenu
     * 
     */
    void enable_menu();

    /**
     * @brief Get the GameState to check the transition: 
     * 0 =  stay on the menu, 
     * 1 = go to choose level menu, or
     * 2 = generate random level and start pause 
     * 
     * @return int 
     */
    int get_state();

    /**
     * @brief reset state and buttons after end screen. 
     * 
     */
    void reset();

    /**
     * @brief forward the events from window to the buttons.
     * 
     * @param window 
     * @param event 
     */
    void handle_events(sf::RenderWindow& window, sf::Event& event);


private:

    /**
     * @brief Set the menu background image
     * 
     */
    void set_menu_background();

    /**
     * @brief Set the transparent buttons on correct places on the background
     * 
     */
    void set_buttons();

    /**
     * @brief draw the background and buttons.s
     * 
     * @param target 
     * @param state 
     */
    void draw(sf::RenderTarget& target, sf::RenderStates state) const;

    /**
     * @brief keeps track of wether the menu is enabled
     * 
     */
    bool _menu_enabled;

    /**
     * @brief keeps track of the next state in the game loop
     * 
     */
    int _state;

    /**
     * @brief a sprite for the background texture
     * 
     */
    sf::Sprite _menu_background;


    /**
     * @brief a pointer for the random level button
     * 
     */
    Button* _random_level_button;

    /**
     * @brief a pointer for the button that forwards to choose level menu
     * 
     */
    Button* _choose_level_button;

    /**
     * @brief a reference to ResourceHandler, get the background texture and font for buttons
     * 
     */
    ResourceHandler& _rh;

    /**
     * @brief a reference to the level
     * 
     */
    Level& _level;


};



#endif