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

    Button(const std::string& label, sf::Vector2f size, sf::Vector2f position, sf::Color fill_color, sf::Color outline_color, const sf::Font& font);
    
    /**
     * @brief Centers the sf::text object to  the middle of the button.
     */ 
    void center_text();

    /**
     * @brief Sets outline color of the button box and color of the text.
     * @param outline_color color of the outline 
     */ 
    void set_outline_color(sf::Color outline_color);

    /**
     * @brief Sets fill color of the button box.
     * @param fill_color color of the outline 
     */  
    void set_fill_color(sf::Color fill_color);
    
    /**
     * @brief Sets the button's text as the given string.
     * @param label
     */  
    void set_text_string(const std::string& label);
    
    /**
     * @brief Sets the position of the button background and centers the text according the button and text size.
     * @param pos
     */   
    void set_position(sf::Vector2f pos);
    
    /**
     * @brief Sets the size of the button.
     * @param size
     */   
    void set_size(sf::Vector2f size);
    
    /**
     * @brief assigns the given reference to a font to the buttons sf::Text object.
     * @param font
     */  
    void set_font(const sf::Font& font);


    /**
     * @brief Returns the buttons size.
     * @return sf::Vector2f 
     */  
    sf::Vector2f get_size();
    
    /**
     * @brief Returns a true value if the button is pressed. Used in if-statements to trigger actions in menus.
     * @return bool
     */ 
    bool button_pressed();

    /**
     * @brief Resets the button. Used after button_pressed in menus. 
     * @return bool
     */ 
    void reset_button();

    /**
     * @brief Resets the button. Used after button_pressed in menus. 
     * @return bool
     */ 
    bool is_mouse_over(sf::RenderWindow& window);

    /**
     * @brief Handle mouse events given from the game class.
     * Makes fill color brighter if mouse hovers on top of button.
     * Makes button less transparent if mouse hovers on top of button (used as transparent in MainMenu and ChooseLevelMenu).
     * Sets button pressed if mouse click is recorded on top of button.
     * 
     * @param window reference to the Game class's render window
     * @param event reference to the Game classes event
     * @param lv reference to the Game classes level class
     * 
     */ 
    void handle_events(sf::RenderWindow& window, const sf::Event& event, Level& lv);
    
    /**
     * @brief Checks if mouse position is inside grid
     * 
     * @param mouse_pos position of the mouse w.r.t window
     * @param lv reference to the Game classes level class
     * @return bool
     */ 
    static bool inside_grid( sf::Vector2i mouse_pos, Level& lv);

    
    /**
     * @brief calculates and returns grid index (column, row) of the level from the mouse position w.r.t window
     * 
     * @param mouse_pos position of the mouse w.r.t window
     * @param lv reference to the Game classes level class
     * @return std::pair<int, int> 
     */ 
    static std::pair<int, int> window_coords_to_grid_index( sf::Vector2i mouse_pos, Level& lv);

    /**
     * @brief calculates and returns Vector2D coords of the level from the mouse position w.r.t window
     * 
     * @param mouse_pos position of the mouse w.r.t window
     * @param lv reference to the Game classes level class
     * @return Vector2D
     */ 
    static Vector2D window_coords_to_level_coords(sf::Vector2i mouse_pos);



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

    /**
     * @brief Fill color of the button.
     */ 
    sf::Color _button_fill_color;

    /**
     * @brief Outline color of the button.
     */ 
    sf::Color _button_outline_color;

    /**
     * @brief Position of the button.
     */ 
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

    /**
     * @brief The state of the button. 
     */ 
    bool _button_pressed;

};


   



#endif