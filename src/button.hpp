#ifndef TOWER_DEFENCE_SRC_BUTTON
#define TOWER_DEFENCE_SRC_BUTTON

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "level.hpp"
#include "vector2d.hpp"
#include "vector2d.hpp"
#include <iostream>

/**
 * @brief A class to represent buttons in menus. Inherits from the sfml Drawable class to hide draw calls.
 * Works as a transparent button in the two first menus and as an opaque button for side menu and upgrade classes.  
 * 
 * @param label what to write in the button
 * @param size  size of the button
 * @param position position of the button
 * @param fill_color color of the button
 * @param outline_color outline color of the button
 * @param font a reference to the games font from resource handler
 */
class Button : public sf::Drawable{

public:
    Button();
    Button(const std::string& label, sf::Vector2f size, sf::Vector2f position, sf::Color fill_color, sf::Color outline_color, const sf::Font& font);

    
    // set the position of the button so that the text is in one of: 
    void center_text();


    void set_outline_color(sf::Color outline_color);
    void set_fill_color(sf::Color fill_color);
    void set_text_string(const std::string& label);
    void set_position(sf::Vector2f pos);
    void set_size(sf::Vector2f size);
    void set_font(const sf::Font& font);

    
    // do something if 
    bool button_pressed();

    // reset button after doing something
    void reset_button();

    virtual bool is_mouse_over(sf::RenderWindow& window);

    // handle button press events etc. 
    virtual void handle_events(sf::RenderWindow& window, const sf::Event& event, Level& lv);
    

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

     /**
     * @brief A function that overwrites the virtual function from sf::Drawable for drawing like window.draw(Button).
     * @param target Target to draw to 
     * @param states not used
     */ 
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /**
     * @brief Background of the button.
     */ 
    sf::RectangleShape _button;
    sf::Color _button_fill_color;
    sf::Color _button_outline_color;



    sf::Vector2f _position;
    
    /**
     * @brief Size of the button.
     */ 
    sf::Vector2f _size;

    /**
     * @brief Text obect of the button.      
     * 
     */ 
    sf::Text _text;

    bool _button_pressed;

};


   



#endif