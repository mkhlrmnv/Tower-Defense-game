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
    Button(const std::string& label, sf::Vector2f size, sf::Vector2f position, sf::Color fill_color, sf::Color outline_color, const sf::Font* font);

    
    // set the position of the button so that the text is in one of: 
    void center_text();


    void set_outline_color(sf::Color outline_color);
    void set_fill_color(sf::Color fill_color);
    void set_text_string(const std::string& label);

    virtual bool is_mouse_over(sf::RenderWindow& window);

    // handle button press events etc. 
    virtual void handle_events(sf::RenderWindow& window, const sf::Event& event, Level& lv);
    
    // TODO: define in child class 
    virtual void some_action_from_level(sf::RenderWindow& window, Level& lv){}


     // check if mouse in s
    static bool inside_grid( sf::Vector2i mouse_pos, Level& lv);
    static bool inside_grid(sf::Vector2f window_coords, Level& lv);

    // use in upgrade button
    static std::pair<int, int> window_coords_to_grid_index( sf::Vector2i mouse_pos, Level& lv);
    static std::pair<int, int> window_coords_to_grid_index( sf::Vector2f window_coords, Level& lv);

    // use in drag_button to check mouse position
    static Vector2D window_coords_to_level_coords(sf::Vector2i mouse_pos);
    static Vector2D window_coords_to_level_coords(sf::Vector2f window_coords);



protected: 

    virtual void draw(sf::RenderTarget& target, sf::RenderStates) const;

    sf::RectangleShape _button;
    sf::Color _button_fill_color;
    sf::Color _button_outline_color;



    sf::Vector2f _position;
    sf::Vector2f _size;
    sf::Text _text;

    // load font locally to g
    const sf::Font* _font;
};


   



#endif