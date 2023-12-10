#include "button.hpp"



Button::Button(const std::string& label, sf::Vector2f size, sf::Vector2f position, sf::Color fill_color, sf::Color outline_color, const sf::Font& font): 
_size(size), _position(position), _button_fill_color(fill_color), _button_outline_color(outline_color), _text(), _button_pressed(false){
    
    _button.setPosition(_position);
    _button.setSize(_size);
    _button.setOutlineThickness(1);
    _button.setFillColor(_button_fill_color);
    _button.setOutlineColor(_button_outline_color); 

    _text.setFont(font);
    _text.setCharacterSize(15);
    _text.setFillColor(_button_outline_color); 
    _text.setString(label);
    _text.setPosition(_button.getPosition());
    
}




void Button::center_text(){

    float text_x = _button.getPosition().x + _button.getGlobalBounds().width / 2 - _text.getGlobalBounds().width / 2;
    float text_y = _button.getPosition().y + _button.getGlobalBounds().height / 2 - _text.getGlobalBounds().height / 2;
    _text.setPosition(text_x, text_y);
}


void Button::set_fill_color(sf::Color fill_color){

    _button_fill_color = fill_color;
    _button_fill_color = fill_color;
    _button.setFillColor(fill_color);
}

void Button::set_outline_color(sf::Color outline_color){

    _button_outline_color = outline_color;
    _button.setOutlineColor(outline_color);
    _text.setFillColor(outline_color);

}


void Button::set_text_string(const std::string& text){

    _text.setString(text);
}

void Button::set_position(sf::Vector2f pos){

    _position = pos;
    _button.setPosition(pos);
    center_text();
}

void Button::set_size(sf::Vector2f size){

    _size = size;
    _button.setSize(size);
    center_text();
}

void Button::set_font(const sf::Font& font){

    _text.setFont(font);

}

sf::Vector2f Button::get_size(){

    return _button.getSize();
}

bool Button::button_pressed(){

    return _button_pressed;
}

void Button::reset_button(){
    
    _button_pressed = false;
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
            
            float a = (_button_fill_color.a + 30 < 255) ? _button_fill_color.a + 30 : 255;  
            float r = (_button_fill_color.r + 10 < 255) ? _button_fill_color.r + 10 : 255; 
            float g = (_button_fill_color.g + 10 < 255) ? _button_fill_color.g + 10 : 255; 
            float b = (_button_fill_color.b + 10 < 255) ? _button_fill_color.b + 10 : 255; 
            sf::Color hover_color(r,g,b,a);
            _button.setFillColor(hover_color);

        }else{
            _button.setFillColor(_button_fill_color);

        }
    }
    
    if(event.type == sf::Event::MouseButtonPressed){
        if(is_mouse_over(window)){    
            _button_pressed = true;
        }
    }
    
}


bool Button::inside_grid(sf::Vector2i mouse_pos, Level& lv){
    
    int x = mouse_pos.x;
    int y = mouse_pos.y;

    int res = lv.get_square_size()*10;
    
    //no need to flip to level as grid is a square
    if(x>0 && x<res && y>0 && y<800){
        return true;
    }else{
        return false;
    }
}


std::pair<int, int> Button::window_coords_to_grid_index(sf::Vector2i mouse_pos, Level& lv){
    
    // NOTE: pass only coords inside game 0<=coord<=800  

    int col = floor((mouse_pos.x)  / lv.get_square_size());
    int row = floor((mouse_pos.y) / lv.get_square_size());

    if(row<0 && row>9 && col<0 && col>9){
        std::cout << "in Button::window_coords_to_grid_index - position out of grid" << std::endl; 
    };

    std::pair<int, int> grid_index = std::make_pair(row, col);
    return grid_index;
}


Vector2D Button::window_coords_to_level_coords(sf::Vector2i mouse_pos){
    
    int x = mouse_pos.y;
    int y = mouse_pos.x;

    return Vector2D(x,y);
    
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates) const {
    
    target.draw(_button);
    target.draw(_text); 
}
