#include <renderer.hpp>


void Renderer::draw_level(sf::RenderWindow& rwindow){
    rwindow.draw(_drawable_level);
}


void Renderer::draw_tower(sf::RenderWindow& rwindow, int type, int ongoing_action, Vector2D position){

     //  just to avoid warning, for now
    int _ = type;
        _ = ongoing_action;

    _drawable_tower.setTexture(_tower_texture.getTexture());
    _drawable_tower.setPosition(sf::Vector2f (position.x - 20, position.y - 20)); // TODO: set off set according to the real texture / img size
    
    rwindow.draw(_drawable_tower);

}

void Renderer::draw_enemy(sf::RenderWindow& rwindow, int type, int ongoing_action, Vector2D position){

    //  just to avoid warning, for now
    int _ = type;
        _ = ongoing_action;

    _drawable_enemy.setTexture(_enemy_texture.getTexture());
    _drawable_enemy.setPosition(sf::Vector2f (position.x - 20, position.y - 20)); // TODO: set off set according to the real texture / img size
    
    rwindow.draw(_drawable_enemy);

}

void Renderer::draw_towers(sf::RenderWindow& rwindow, std::vector<Tower*> towers){
    for(Tower* t_ptr : towers){
        draw_tower(rwindow, 0, 0, t_ptr->get_position());
    }
}

void Renderer::draw_enemies(sf::RenderWindow& rwindow, std::vector<Enemy*> enemies){
    for(Enemy* e_ptr : enemies){
        draw_enemy(rwindow, 0, 0, e_ptr->get_position());
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
    triangle.setFillColor(red);
    _enemy_texture.draw(triangle);
    _enemy_texture.display();

    sf::Color blue(0,0,128);
    triangle.setFillColor(blue);
    _tower_texture.draw(triangle);
    _tower_texture.display();

}
