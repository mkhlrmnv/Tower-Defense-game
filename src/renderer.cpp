#include <renderer.hpp>


void Renderer::draw_level(sf::RenderWindow& rwindow){
    rwindow.draw(_drawable_level);
}


void Renderer::draw_tower(sf::RenderWindow& rwindow, int type, int ongoing_action, Vector2D position){

    //  just to avoid warning for now, later use type and object state to select correct texture
    int _ = type;
        _ = ongoing_action;

    _drawable_tower.setTexture(_tower_texture.getTexture());
    _drawable_tower.setPosition(sf::Vector2f (position.x - 20, position.y - 20)); // TODO: set offset according to the real texture / img size
    
    rwindow.draw(_drawable_tower);

}

void Renderer::draw_enemy(sf::RenderWindow& rwindow, int type, int ongoing_action, Vector2D position){

    // just to avoid warning for now, later use type and object state to select correct texture
    int _ = type;
        _ = ongoing_action;

    _drawable_enemy.setTexture(_enemy_texture.getTexture());
    _drawable_enemy.setPosition(sf::Vector2f (position.x - 20, position.y - 20)); // TODO: set offset according to the real texture / img size
    
    rwindow.draw(_drawable_enemy);

}

void Renderer::draw_towers(sf::RenderWindow& rwindow, std::vector<Tower*> towers){
    for(Tower* t_ptr : towers){
        draw_tower(rwindow, 0, 0, t_ptr->get_position()); // zeros are placeholders
    }
}

void Renderer::draw_enemies(sf::RenderWindow& rwindow, std::vector<Enemy*> enemies){
    for(Enemy* e_ptr : enemies){
        draw_enemy(rwindow, 0, 0, e_ptr->get_position()); // zeros are placeholders
    }
}

void Renderer::draw_cash(sf::RenderWindow& rwindow, int cash){

    std::string text_to_be_displayed = "$" + std::to_string(cash);
    _cash_text.setString(text_to_be_displayed);
    rwindow.draw(_cash_text);
}

void Renderer::draw_lives(sf::RenderWindow& rwindow, int lives){

    std::string text_to_be_displayed = "Lives: " + std::to_string(lives);
    _lives_text.setString(text_to_be_displayed);
    rwindow.draw(_lives_text);
}

void Renderer::draw_round_count(sf::RenderWindow& rwindow, int round_count){

    std::string text_to_be_displayed = "Round: " + std::to_string(round_count);
    _round_count_text.setString(text_to_be_displayed);
    rwindow.draw(_round_count_text);
}

// draws a grid with the rectangle to a rendertexture and sets this as the texture for the drawable level
void Renderer::make_drawable_level(Level& lv){
    // pass the level argument with existing grid, either from random generation or loaded from file

    if(!_level_texture.create(lv.get_square_size()*10, lv.get_square_size()*10)){ 
        std::cout << "RenderTexture creation failed for level" << std::endl;
    }    
    
    int square_type; 
    Vector2D center_coords;
    int upper_left_corner_x; 
    int upper_left_corner_y;

    // TODO: change colors and RectangleShape to textures
    sf::Color green = sf::Color(0, 128, 0);
    sf::Color grey = sf::Color(128, 128, 128);
    
    sf::RectangleShape drawable_level_square = sf::RectangleShape(sf::Vector2f(lv.get_square_size(),lv.get_square_size()));
    std::vector<std::vector<Square *>> level_grid = lv.get_grid();

    for(auto column : level_grid){
        for(auto square : column){
            square_type = square->get_occupied();
            center_coords = square->get_center();
            // get the upper left corner position of a level grid, position of the graphic objects is taken from the upper left corner
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

// Uses same triangle to set a place holder texture for both enemy and tower class
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

void Renderer::load_font(){
    if(!_font.loadFromFile("../assets/fonts/Ubuntu-R.ttf")){
        std::cout << "font load failed" << std::endl;
    }else{
        std::cout << "font load success" << std::endl;

    }
}

void Renderer::make_level_info_texts(int game_resolution, int side_bar_width){

    load_font();

    _cash_text.setFont(_font);
    _lives_text.setFont(_font);
    _round_count_text.setFont(_font);

    int info_display_height = 20;
    int info_display_width = side_bar_width / 3;

    int cash_x = game_resolution;
    int cash_y = game_resolution - info_display_height;

    _cash_text.setPosition(sf::Vector2f(cash_x, cash_y));
    _cash_text.setFillColor(sf::Color::White);
    _cash_text.setCharacterSize(20);

    int lives_x = cash_x + info_display_width;
    int lives_y = game_resolution - info_display_height;

    _lives_text.setPosition(sf::Vector2f(lives_x, lives_y));
    _lives_text.setFillColor(sf::Color::White);
    _lives_text.setCharacterSize(20);

    int round_count_x = lives_x + info_display_width;
    int round_count_y = game_resolution - info_display_height;

    _round_count_text.setPosition(sf::Vector2f(round_count_x, round_count_y));
    _round_count_text.setFillColor(sf::Color::White);
    _round_count_text.setCharacterSize(20);
}   
