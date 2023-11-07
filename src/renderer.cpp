#include <renderer.hpp>


void Renderer::draw_level(sf::RenderWindow& rwindow){
    rwindow.draw(_drawable_level);
}


void Renderer::draw_object(sf::RenderWindow& rwindow, int type, int ongoing_action, Vector2D position){


    // choose texture based on type, for no just use the square.occupied_by() 
    int tower = 0;
    int enemy = 2;

    // just to avoid warning, for now
    int  _ = ongoing_action;

    if(type == enemy){
        _drawable_object.setTexture(_enemy_texture.getTexture());
    }else if(type == tower){
        _drawable_object.setTexture(_tower_texture.getTexture());
    }
    // offset the position according the size
    _drawable_object.setPosition(sf::Vector2f (position.x - 20, position.y- 20));
    
    rwindow.draw(_drawable_object);

}

//TODO:: for now call this with homogeneous list of enemies or towers with occupied: tower = tower, enemy = road, later use type from objects, 
void Renderer::draw_objects(sf::RenderWindow& rwindow, std::vector<Object*> objs, int enemy_or_tower){
    for(Object* obj_ptr : objs){
        draw_object(rwindow, enemy_or_tower, 0, obj_ptr->get_position());
    }
}


void Renderer::make_drawable_level(Level& lv){
    // pass the level argument with existing grid, either from random generation or loaded from file

    if(!_level_texture.create(lv.get_square_size()*10, lv.get_square_size()*10)){ 
        std::cout << "RenderTexture creation failed for level" << std::endl;
    }    
    
    int square_type; 
    Vector2D center_coords;
    int upper_left_corner_x; 
    int upper_left_corner_y;

    // TODO: change colors to textures
    sf::Color green = sf::Color(0, 128, 0);
    sf::Color grey = sf::Color(128, 128, 128);
    
    sf::RectangleShape drawable_level_square = sf::RectangleShape(sf::Vector2f(lv.get_square_size(),lv.get_square_size()));


    std::vector<std::vector<Square *>> level_grid = lv.get_grid();
    for(auto column : level_grid){
        for(auto square : column){
            square_type = square->get_occupied();
            center_coords = square->get_center();
            // position of the graphic objects is taken from the upper left corner
            upper_left_corner_x  = center_coords.x - lv.get_square_size()/2;
            upper_left_corner_y  = center_coords.y - lv.get_square_size()/2;
            
            drawable_level_square.setPosition(upper_left_corner_y, upper_left_corner_x);
            drawable_level_square.setOutlineColor(grey);

            if(square_type == occupied_type::grass){
                drawable_level_square.setOutlineThickness(-0.5);
                drawable_level_square.setFillColor(green);
            }
            else if(square_type == occupied_type::road){
                drawable_level_square.setOutlineThickness(0);
                drawable_level_square.setFillColor(grey);
            }
            _level_texture.draw(drawable_level_square);
        }
    }

    _level_texture.display();
    _drawable_level.setTexture(_level_texture.getTexture());
}

void Renderer::make_drawable_object_textures(){

    _tower_texture.create(40, 40);
    _enemy_texture.create(40, 40);

    sf::ConvexShape triangle(3);
    triangle.setPoint(0, sf::Vector2f(20, 0));
    triangle.setPoint(1, sf::Vector2f(0, 40));
    triangle.setPoint(2, sf::Vector2f(40, 40));
    triangle.setPosition(sf::Vector2f(0, 0));

    sf::Color red(128,0,0);
    sf::Color blue(0,0,128);
    triangle.setFillColor(red);
    _enemy_texture.draw(triangle);
    _enemy_texture.display();

    triangle.setFillColor(blue);
    _tower_texture.draw(triangle);
    _tower_texture.display();
}
