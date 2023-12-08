#ifndef TOWER_DEFENCE_SRC_UPGRADE
#define TOWER_DEFENCE_SRC_UPGRADE

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "button.hpp"
#include "resource_handler.hpp"
#include <memory>
#include <iostream>

/**
 * @brief A class to implement tower upgrades. Click a object on the grid and a menu will pop. Push upgrade button to upgrade the tower's attributes.
 * Basic idea: 
 * 1. click grid position. 
 * 2. if there is a tower: pop menu with current attributes of the tower on the square
 * 3. press button to call tower_to_be_upgraded->level_up()
 * 4. hide menu 
 * 
 * @param grid_resolution
 * @param rh
 * @param level
 * @param upgrade_cost
 */
class Upgrade : public sf::Drawable{
public:

    Upgrade(float grid_resolution, ResourceHandler& rh, Level& level, int upgrade_cost, int max_upgrades);
    ~Upgrade(){delete _upgrade_button;}
    Upgrade(const Upgrade&) = delete; 
    Upgrade& operator=(const Upgrade&) = delete;
   
    /**
     * @brief Handles events from the game.
     *
     * 
     * @param window 
     * @param event 
     */
    void handle_events(sf::RenderWindow& window, sf::Event& event);
    
    
    /**
     * @brief Disable grid click.
     * 
     */
    void disable_grid_click();

    /**
     * @brief Reset upgrade so the menu wont stay to next game.
     * 
     */
    void reset();


private:

    /**
     * @brief Checks if mouse click is outside the popped upgrade menu
     * 
     * @param mouse_pos 
     * @return true 
     * @return false 
     */
    bool outside_menu(sf::Vector2i mouse_pos);

    /**
     * @brief Checks if mouse position is inside grid.
     * 
     * @param mouse_pos 
     * @return true 
     * @return false 
     */
    bool inside_grid(sf::Vector2i mouse_pos);

    // 
    // 
    /**
     * @brief Get tower to upgrade from grid if such exist on a square. 
     * 
     * @param mouse_pos 
     */
    void grid_click(sf::Vector2i mouse_pos);

    /**
     * @brief Pops the upgrade menu on the given position.
     * The menu displays tower stats and upgrade button.
     * 
     * @param pop_here 
     */
    void pop_upgrade_menu(sf::Vector2f pop_here);

    /**
     * @brief Close the upgrade menu, disable button.
     * 
     */
    void close_upgrade_menu();

    /**
     * @brief Setup the menus sprite, rectangleshape and text objects
     * 
     */
    void setup_menu();

    /**
     * @brief Setup the text line, with image and text
     * 
     * @param sprite 
     * @param text 
     * @param pos 
     * @param color 
     * @param attr_type 
     * @param char_size 
     */
    void setup_text_line(sf::Sprite& sprite, sf::Text &text, sf::Vector2f pos, sf::Color color, int attr_type, int char_size);

    /**
     * @brief Updates the menus position, and the attributes according to the selected tower.
     * 
     * @param position 
     */
    void set_menu(sf::Vector2f position);

    /**
     * @brief Set the position of text lines in set menu function.
     * 
     * @param sprite 
     * @param text 
     * @param pos 
     * @param attr 
     */
    void set_text_line(sf::Sprite& sprite, sf::Text &text, sf::Vector2f pos, int attr);

    
    /**
     * @brief Calls tower.upgrade() if theres enough money to upgrade and removes price of upgrade from cash in level.
     * 
     */
    void upgrade_tower();

    
    /**
     * @brief The inherited method from sf::Drawable class, just pass this object as argument to window.draw() to handle drawing.
     * 
     * @param target 
     * @param states 
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /**
     * @brief a background for the menu
     * 
     */
    sf::RectangleShape _background;

    // put image in to button;
   

    /**
     * @brief a ptr to the upgrade button
     * 
     */
    Button* _upgrade_button;

    /**
     * @brief a sprite for the image of the hp
     * 
     */
    sf::Sprite _hp_img;

    /**
     * @brief a sprite for the image of the hp
     * 
     */
    sf::Sprite _dmg_img;

    /**
     * @brief a sprite for the image of the range
     * 
     */
    sf::Sprite _rng_img;

    /**
     * @brief a sprite for the image of the attack speed
     * 
     */
    sf::Sprite _atkspd_img;
    
    /**
     * @brief a text for the name
     * 
     */
    sf::Text _name_text;

    /**
     * @brief  a text object for the hp
     * 
     */
    sf::Text _hp_text;

    /**
     * @brief  a text object for the damage
     * 
     */
    sf::Text _dmg_text;

    /**
     * @brief a text object for the range
     * 
     */
    sf::Text _rng_text;

    /**
     * @brief a text object for the attack speed
     * 
     */
    sf::Text _atkspd_text;

    /**
     * @brief a text object for the price
     * 
     */
    sf::Text _price_text;


    /**
     * @brief if menu is popped
     *  if false
     *  - click tower on grid -> _upgrade_menu_enabled = true;
     *
     *  if true 
     *  -click button upgrade_tower
     *  -click menu nothing
     *  -click outside menu or button close menu and button, set _upgrade_menu_enabled false;
     */
    bool _upgrade_menu_enabled;


    /**
     * @brief Tells if the upgrade feature is active
     * Prevents the menu suriving after end screen to new game.
     *  
     */
    bool _upgrade_enabled;

    /**
     * @brief a reference to ResourceHandler, handles textures
     * 
     */
    ResourceHandler& _rh;

    /**
     * @brief a reference of the level class from the game
     * 
     */
    Level& _level;

    /**
     * @brief a pointer to the tower that is to be upgraded
     * 
     */
    Tower* _tower_to_upgrade;

    /**
     * @brief the cost of the upgrade
     * 
     */
    int _upgrade_cost;

    /**
     * @brief the number of tower upgrades
     * 
     */
    int _max_upgrades;

};





#endif

