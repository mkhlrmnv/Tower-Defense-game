#ifndef TOWER_DEFENCE_SRC_CHOOSE_LEVEL_MENU
#define TOWER_DEFENCE_SRC_CHOOSE_LEVEL_MENU


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "level.hpp"
#include "resource_handler.hpp"
#include "button.hpp"

#include <iostream>

/**
 * @brief a class representing the level selection menu.
 * @param ResourceHandler&
 * @param Level&
 */

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

    ChooseLevelMenu(const ChooseLevelMenu&) = delete; 
    ChooseLevelMenu& operator=(const ChooseLevelMenu&) = delete;

    
    /**
     * @brief Disables menu.
     * 
     */
    void disable_menu();

    /**
     * @brief Enables menu.
     * 
     */
    void enable_menu();

    /**
     * @brief Get the GameState to check the transition in Game class:
     * 1 = stay on the menu
     * 2 = load level in transtion and start game with pause 
     * 
     * @return int 
     */
    int get_state();

    /**
     * @brief Resets state and buttons.
     * 
     */
    void reset();

    /**
     * @brief Forwards the events from window to the buttons.
     * 
     * @param window 
     * @param event 
     */
    void handle_events(sf::RenderWindow& window, sf::Event& event);

    /**
     * @brief Get the level to load for level.load_file()
     * 
     * @return const std::string 
     */
    const std::string get_level_to_load();


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
     * @brief Keeps track of wether the menu is enabled
     * 
     */
    bool _menu_enabled;

    /**
     * @brief Holds the level number which is set with by handle events. 
     * Used in get_level_to_load(). 
     * Default value is set to -1 - no corresponding level files.  
     * 
     */
    int _level_number;

    /**
     * @brief Keeps track of the next state in the game loop
     * 
     */
    int _state;

    /**
     * @brief A sprite for the background texture
     * 
     */
    sf::Sprite _menu_background;


    /**
     * @brief Transparent button for level 1.
     * 
     */
    Button* _level1_button;

    /**
     * @brief Transparent button for level 2.
     * 
     */
    Button* _level2_button;

    /**
     * @brief Transparent button for level 3.
     * 
     */
    Button* _level3_button;

    /**
     * @brief Transparent button for level 4.
     * 
     */
    Button* _level4_button;

    /**
     * @brief Transparent button for level 5.
     * 
     */
    Button* _level5_button;

    /**
     * @brief Transparent button for level 6.
     * 
     */
    Button* _level6_button;

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