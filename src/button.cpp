#include "button.hpp"


Button::Button(const std::string& label, sf::Vector2f size, sf::Vector2f position, sf::Color fill_color, sf::Color outline_color, const sf::Font* font): 
_size(size), _position(position), _button_fill_color(fill_color), _button_outline_color(outline_color), _text(), _font(font){
    
    _button.setPosition(_position);
    _button.setSize(_size);
    _button.setOutlineThickness(1);
    _button.setFillColor(_button_fill_color);
    _button.setOutlineColor(_button_outline_color); 

    _text.setFont(*_font);
    _text.setCharacterSize(20);
    _text.setFillColor(_button_outline_color); 
    _text.setString(label);
    _text.setPosition(_button.getPosition());
    
    
    /* 
    std::cout << "_text.getGlobalBounds().height " << _text.getGlobalBounds().height << std::endl;
    std::cout << "_text.getGlobalBounds().width " << _text.getGlobalBounds().width << std::endl;
    std::cout << "_text.getGlobalBounds().left " << _text.getGlobalBounds().left << std::endl;
    std::cout << "_text.getGlobalBounds().top " << _text.getGlobalBounds().top << std::endl;

    std::cout << "_text.getLocalBounds().height " << _text.getLocalBounds().height << std::endl;
    std::cout << "_text.getLocalBounds().width " << _text.getLocalBounds().width << std::endl;
    std::cout << "_text.getLocalBounds().left " << _text.getLocalBounds().left << std::endl;
    std::cout << "_text.getLocalBounds().top " << _text.getLocalBounds().top << std::endl;
    */
    
}




void Button::center_text(){

    //TODO: FIX CENTER TEXT HORIZONTALLY
    float text_x = _button.getPosition().x + _button.getGlobalBounds().width / 2 - _text.getGlobalBounds().width / 2;
    float text_y = _button.getPosition().y + _button.getGlobalBounds().height / 2 - _text.getGlobalBounds().height / 2;
    _text.setPosition(text_x, text_y);
}



void Button::set_fill_color(sf::Color fill_color){
    _button_fill_color = fill_color;
    _button.setFillColor(fill_color);
}

void Button::set_outline_color(sf::Color outline_color){
    _button_outline_color = outline_color;
    _button.setOutlineColor(outline_color);
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

sf::Vector2f Button::get_size(){
    return _button.getSize();
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

bool Button::inside_grid(sf::Vector2i mouse_pos, Level& lv){
    
    int x = mouse_pos.x;
    int y = mouse_pos.y;

    int res = lv.get_square_size()*10;
    
    // dont care to flip to level as grid is a square
    if(x>0 && x<res && y>0 && y<800){
        return true;
    }else{
        return false;
    }
}

bool Button::inside_grid(sf::Vector2f window_coords, Level& lv){
    
    int x = static_cast<int>(window_coords.x);
    int y = static_cast<int>(window_coords.y);
    
    int res = lv.get_square_size()*10;
    
    // dont care to flip to level as grid is a square
    if(x>0 && x<res && y>0 && y<800){
        return true;
    }else{
        return false;
    }
}


std::pair<int, int> Button::window_coords_to_grid_index(sf::Vector2i mouse_pos, Level& lv){
    
    // NOTE: pass only coords inside game 0<=coord<=800  

    int row = floor((mouse_pos.x)  / lv.get_square_size());
    int col = floor((mouse_pos.y) / lv.get_square_size());

    if(row<0 && row>9 && col<0 && col>9){
        std::cout << "in Button::window_coords_to_grid_index - position out of grid" << std::endl; 
    };

    std::pair<int, int> grid_index = std::make_pair(row, col);
    return grid_index;
}

std::pair<int, int> Button::window_coords_to_grid_index(sf::Vector2f window_coords, Level& lv){
    

    // NOTE: pass only coords inside game 0<=coord<=800  

    int row = floor(window_coords.x / lv.get_square_size());
    int col = floor(window_coords.y / lv.get_square_size());

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

Vector2D Button::window_coords_to_level_coords(sf::Vector2f window_coords){
    
    int x = static_cast<int>(window_coords.y);
    int y = static_cast<int>(window_coords.x);

    return Vector2D(x,y);
    
}




void Button::handle_events(sf::RenderWindow& window, const sf::Event& event, Level& level){

    if (event.type == sf::Event::MouseMoved){
        if(is_mouse_over(window)){
            // TODO: implicate some how that button can be pressed
            set_fill_color(sf::Color::Yellow);
        }else{
            set_fill_color(sf::Color::Red);
        }
    }
    
    if(event.type == sf::Event::MouseButtonPressed){
        if(is_mouse_over(window)){
            set_fill_color(sf::Color::Green);
            some_action_from_level(window, level); // TODO: ad some function to do something
        }
    }
    
}


void Button::draw(sf::RenderTarget& target, sf::RenderStates) const {
    target.draw(_button);
    target.draw(_text); 
}
