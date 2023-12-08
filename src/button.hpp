#ifndef TOWER_DEFENCE_SRC_BUTTON
#define TOWER_DEFENCE_SRC_BUTTON

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "level.hpp"
#include <iostream>


class Button : public sf::Drawable{

public:
    Button(){}
    Button(const std::string& label, sf::Vector2f size, sf::Vector2f position, sf::Color color);

    void set_font(sf::Font& font);
    
    // set the position of the button so that the text is in one of: 
    void set_position_text_up(sf::Vector2f pos);
    void set_position_text_middle(sf::Vector2f pos);
    void set_position_text_down(sf::Vector2f pos);

    void set_color(sf::Color color);
    void set_text_string(const std::string& label);

    bool is_mouse_over(sf::RenderWindow& window);

    virtual void handle_events(sf::RenderWindow& window, const sf::Event& event, Level& lv);

    // TODO: define in child class 
    virtual void some_action_from_level(Level &lv){} 


protected: 

    virtual void draw(sf::RenderTarget& target, sf::RenderStates) const;

    sf::RectangleShape _button;
    sf::Color _button_color;

    sf::Vector2f _position;
    sf::Vector2f _size;
    sf::Text _text;
    
};




#endif