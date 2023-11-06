#include <renderer.hpp>


void Renderer::draw_level(sf::RenderWindow& rwindow){
    rwindow.draw(_drawable_level);
}

void Renderer::make_drawable_level(const Level& lv){
    // pass the level argument with existing grid, either from random generation or loaded from filed 

    if(!_level_texture.create(lv.get_square_size()*10, lv.get_square_size()*10)){ 
        std::cout << "RenderTexture creation failed for level" << std::endl;
    }    
    
    int square_type; 
    Vector2D center_coords;
    int upper_left_corner_x; 
    int upper_left_corner_y;

    std::vector<std::vector<Square *>> level_grid = lv.get_grid();
    for(auto column : level_grid){
        for(auto square : column){
            square_type = square->get_occupied();
            center_coords = square->get_center();
            // position of the graphic objects is taken from the upper left corner
            upper_left_corner_x  = center_coords.x - lv.get_square_size()/2;
            upper_left_corner_y  = center_coords.y - lv.get_square_size()/2;
            // TODO: change to textures
            sf::Color green = sf::Color(0, 128, 0);
            sf::Color grey = sf::Color(128, 128, 128);
            sf::RectangleShape drawable_level_square = sf::RectangleShape(sf::Vector2f(lv.get_square_size(),lv.get_square_size()));
            drawable_level_square.setPosition(upper_left_corner_y, upper_left_corner_x);
            
            if(square_type == occupied_type::grass){
                drawable_level_square.setFillColor(green);
            }
            else if(square_type == occupied_type::road){
                drawable_level_square.setFillColor(grey);
            }
            _level_texture.draw(drawable_level_square);
        }
    }

    _level_texture.display();
    _drawable_level.setTexture(_level_texture.getTexture());
}