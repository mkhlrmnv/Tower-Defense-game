#include "button.hpp"


Button::Button(const std::string& label, sf::Vector2f size, sf::Vector2f position, sf::Color color): 
_size(size), _position(position), _button_color(color){
    
    _button.setSize(_size);
    _button.setPosition(_position);    
    _button.setOutlineThickness(1);
    _button.setFillColor(color);
    _button.setOutlineColor(sf::Color::White); // TODO: decide

    _text.setCharacterSize(20);
    set_position_text_middle(_position);
    _text.setFillColor(sf::Color::White);  // TODO: decide
    _text.setString(label);

}

void Button::set_font(sf::Font& font){
    _text.setFont(font);
}

void Button::set_position_text_up(sf::Vector2f pos){

    //TODO: FIX CENTER TEXT HORIZONTALLY


    _position = pos;
    _button.setPosition(pos);
    float text_x = pos.x + _button.getGlobalBounds().width / 2 - _text.getGlobalBounds().width/2;
    float text_y = pos.y;
    _text.setPosition(text_x, text_y);
}

void Button::set_position_text_middle(sf::Vector2f pos){

    //TODO: FIX CENTER TEXT HORIZONTALLY


    _button.setPosition(pos);
    float text_x = pos.x + _button.getGlobalBounds().width / 2 - _text.getGlobalBounds().width/2;
    float text_y = pos.y + _button.getGlobalBounds().height / 2 - _text.getCharacterSize()/2;
    _text.setPosition(text_x, text_y);
}

void Button::set_position_text_down(sf::Vector2f pos){

    //TODO: FIX CENTER TEXT HORIZONTALLY

    std::cout << _button.getGlobalBounds().width << std::endl;

    float additional_distance_to_bottom = 5;

    _button.setPosition(pos);

    float text_x = _button.getPosition().x + _button.getGlobalBounds().width / 2 - _text.getLocalBounds().width/2;
    float text_y = _button.getPosition().y + _button.getGlobalBounds().height - _text.getCharacterSize() - additional_distance_to_bottom;

    _text.setPosition({text_x, text_y});
}

void Button::set_color(sf::Color color){
    _button_color = color;
    _button.setFillColor(color);
}

void Button::set_text_string(const std::string& text){
    _text.setString(text);
}

bool Button::is_mouse_over(sf::RenderWindow &window){
    float mouse_x = sf::Mouse::getPosition(window).x;
    float mouse_y = sf::Mouse::getPosition(window).y;

    float button_x = _button.getPosition().x;
    float button_y = _button.getPosition().y;

    float button_width_x = button_x + _button.getGlobalBounds().width;
    float button_height_y = button_y + _button.getGlobalBounds().height;

    // if mouse is inside bounds return true else false
    return (button_x < mouse_x) && (mouse_x < button_width_x) && (button_y < mouse_y) && (mouse_y < button_height_y);

}


void Button::handle_events(sf::RenderWindow& window, const sf::Event& event, Level& level){

    if (event.type == sf::Event::MouseMoved){
        if(is_mouse_over(window)){
            // TODO: implicate some how that button can be pressed
            set_color(sf::Color::Yellow);
        }else{
            set_color(sf::Color::Red);
        }
    } 
    if(event.type == sf::Event::MouseButtonPressed){
        if(is_mouse_over(window)){
            set_color(sf::Color::Green);
            some_action_from_level(level); // TODO: ad some functoin to do something
        }
    }
}


void Button::draw(sf::RenderTarget& target, sf::RenderStates) const {
    target.draw(_button);
    target.draw(_text); 
}
