#ifndef TOWER_DEFENCE_SRC_UPGRADE
#define TOWER_DEFENCE_SRC_UPGRADE

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "button.hpp"
#include "resource_handler.hpp"
#include <memory>
#include <iostream>


class Upgrade : public sf::Drawable{
public:

    Upgrade(float grid_resolution, ResourceHandler& rh, Level& level, int upgrade_cost);
    ~Upgrade(){delete _upgrade_button;}


    void update();

    void handle_events(sf::RenderWindow& window, sf::Event& event);
    
    
    // disable grid click when dragging towers, or when upgrade menu is displayed
    void disable_grid_click();


private:


    bool outside_menu(sf::Vector2i mouse_pos);
    bool inside_grid(sf::Vector2i mouse_pos);

    // get tower to upgrade from grid
    // or do nothing
    void grid_click(sf::Vector2i mouse_pos);

    // displays tower stats and displays upgrade button
    void pop_upgrade_menu(sf::Vector2f pop_here); 
    void close_upgrade_menu();

    void setup_menu();
    void setup_text_line(sf::Sprite& sprite, sf::Text &text, sf::Vector2f pos, sf::Color color, int attr_type, int char_size);

    void set_menu(sf::Vector2f position);
    void set_text_line(sf::Sprite& sprite, sf::Text &text, sf::Vector2f pos, int attr);

    float max_line_width();

    // call this function
    // call some upgrade function in tower
    // remove price of upgrade from cash in level
    void upgrade_tower();

    // just pass this object as argument to window.draw() to handle drawing 
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;


    sf::RectangleShape _background;

    // put image in to button;
    sf::Sprite _upgrade_button_img;
    Button* _upgrade_button;

    sf::Sprite _hp_img;
    sf::Sprite _dmg_img;
    sf::Sprite _rng_img;
    sf::Sprite _atkspd_img;
    

    sf::Text _name_text;

    sf::Text _hp_text;
    sf::Text _dmg_text;
    sf::Text _rng_text;
    sf::Text _atkspd_text;

    sf::Text _price_text;

    /* if false
        click tower on grid -> select tower, pop menu
    
        if true 
        click button upgrade_tower
        click menu nothing
        click outside menu or button close menu and button, set _upgrade_menu_enabled false;
    */
    bool _upgrade_menu_enabled;
    ResourceHandler& _rh;
    Level& _level;
    Tower* _tower_to_upgrade;
    int _upgrade_cost;

};





#endif

