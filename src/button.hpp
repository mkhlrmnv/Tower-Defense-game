#ifndef TOWER_DEFENCE_SRC_BUTTON
#define TOWER_DEFENCE_SRC_BUTTON

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "level.hpp"
#include "vector2d.hpp"
#include <iostream>


class Button : public sf::Drawable{

public:
    Button(){}
    Button(const std::string& label, sf::Vector2f size, sf::Vector2f position, sf::Color fill_color, sf::Color outline_color);

    void set_font(sf::Font& font);
    
    // set the position of the button so that the text is in one of: 
    void set_position_text_up(sf::Vector2f pos); // TODO: fix or scrap
    void set_position_text_middle(sf::Vector2f pos);
    void set_position_text_down(sf::Vector2f pos);

    void set_outline_color(sf::Color outline_color);
    void set_fill_color(sf::Color fill_color);
    void set_text_string(const std::string& label);

    virtual bool is_mouse_over(sf::RenderWindow& window);


    // check if mouse in s
    bool inside_grid( sf::Vector2i mouse_pos, Level& lv);
    bool inside_grid(sf::Vector2f window_coords, Level& lv);


    // use in upgrade button
    std::pair<int, int> window_coords_to_grid_index( sf::Vector2i mouse_pos, Level& lv);
    std::pair<int, int> window_coords_to_grid_index( sf::Vector2f window_coords, Level& lv);


    // use in drag_button to check mouse position
    Vector2D window_coords_to_level_coords(sf::Vector2i mouse_pos);
    Vector2D window_coords_to_level_coords(sf::Vector2f window_coords);


    // handle button press events etc. 
    virtual void handle_events(sf::RenderWindow& window, const sf::Event& event, Level& lv);


    
    // TODO: define in child class 
    virtual void some_action_from_level(sf::RenderWindow& window, Level& lv){}



protected: 

    virtual void draw(sf::RenderTarget& target, sf::RenderStates) const;

    sf::RectangleShape _button;
    sf::Color _button_fill_color;
    sf::Color _button_outline_color;



    sf::Vector2f _position;
    sf::Vector2f _size;
    sf::Text _text;
    
};




#endif