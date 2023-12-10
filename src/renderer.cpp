#include <renderer.hpp>

Renderer::Renderer():
    _rh(ResourceHandler()){};

void Renderer::draw_level(sf::RenderWindow& rwindow){
    rwindow.draw(_drawable_level);
}

void Renderer::draw_tower(sf::RenderWindow& rwindow, Tower* t_ptr, int frame){

    // from resource handler takes right spread sheet
    _tower_sprite = _rh.get_texture_tower(t_ptr->get_type());
    
    // sets sprite as texture
    _drawable_tower.setTexture(_tower_sprite);

    // variable for where animation is on spread sheet
    int animation_pos;

    // picks right animation value for current tower state
    if (t_ptr->get_state() == State::none) {
        animation_pos = 0;
        frame = 0;
    } else if (t_ptr->get_state() == State::attacking_right || t_ptr->get_state() == State::attacking_left){
        animation_pos = 1;
        // because attacking animation is only 3 frames
        // it stops on third picture
        if (frame > 2){
            animation_pos = 0;
            frame = 0;
        }
    } else if (t_ptr->get_state() == State::dying){
        animation_pos = 4;
        if (frame > 4){ // stops animation in right place
            animation_pos = 0;
            frame = 0;
        }
    }

    // picks right picture from spread sheet
    _drawable_tower.setTextureRect(sf::IntRect((frame + animation_pos) * 32, 0 * 32, 32, 32));

    // pointers for level and square
    Level& l = t_ptr->get_level_reference();
    Square* sq = l.current_square(t_ptr);

    // if attacking left use normal sprite and if right mirror is horizontally
    if (t_ptr->get_state() == State::attacking_right){
        _drawable_tower.setScale(_scale_factor_tower, _scale_factor_tower);
        _drawable_tower.setPosition(sf::Vector2f (sq->get_center().y - (l.get_square_size() / 2), sq->get_center().x - (l.get_square_size() / 2)));
    } else {
        _drawable_tower.setScale(-_scale_factor_tower, _scale_factor_tower);
        _drawable_tower.setPosition(sf::Vector2f (sq->get_center().y - (l.get_square_size() / 2) + l.get_square_size(), sq->get_center().x - (l.get_square_size() / 2)));

        
    }

    // Sets tower position to center of the square and draws it
    rwindow.draw(_drawable_tower);
}

void Renderer::draw_enemy(sf::RenderWindow& rwindow, Enemy* e_ptr, int frame, int move_animation) {
    _enemy_sprite = _rh.get_texture_enemy(e_ptr->get_type());
    _drawable_enemy.setTexture(_enemy_sprite);

    int animation_pos = 0;

    if (e_ptr->get_state() == State::attacking_right || e_ptr->get_state() == State::attacking_left) {
        animation_pos = 1;
        if (frame > 2) {
            animation_pos = 0;
            frame = 0;
        }
    } else if (e_ptr->get_state() == State::walking_left || e_ptr->get_state() == State::walking_right) {
        animation_pos = 4;
        frame = move_animation;
        if (frame > 3) {
            animation_pos = 0;
            frame = 0;
        }
    } else if (e_ptr->get_state() == State::dying) {
        animation_pos = 8;
        frame = std::min(frame, 4);
    }

    int spriteWidth = 32;

    // Makes sure that animations isn't getting outside spreadsheet
    if ((frame + animation_pos) * spriteWidth <= _drawable_enemy.getTexture()->getSize().x){
        _drawable_enemy.setTextureRect(sf::IntRect((frame + animation_pos) * spriteWidth, 0, spriteWidth, spriteWidth));
    } else {
       _drawable_enemy.setTextureRect(sf::IntRect(0, 0, spriteWidth, spriteWidth));
    }

    float scale_factor_enemy = 1.0f; // Adjust as needed
    _drawable_enemy.setScale((e_ptr->get_state() == State::walking_left || e_ptr->get_state() == State::attacking_left) ? scale_factor_enemy : -scale_factor_enemy, scale_factor_enemy);

    float renderedX = e_ptr->get_position().y + 20;
    float renderedY = e_ptr->get_position().x - _drawable_enemy.getTexture()->getSize().y;

    // Ensure enemy isn't drawn outside the field
    renderedX = std::max(renderedX, 1.0f);
    renderedY = std::max(renderedY, 1.0f);

    _drawable_enemy.setPosition(renderedX, renderedY);
    rwindow.draw(_drawable_enemy);
}

// function to draw multiple towers at once
void Renderer::draw_towers(sf::RenderWindow& rwindow, std::vector<Tower*> towers, int frame){
    for(Tower* t_ptr : towers){
        draw_tower(rwindow, t_ptr, frame); // zeros are placeholders
    }
}
 // function to draw multiple enemies at once
void Renderer::draw_enemies(sf::RenderWindow& rwindow, std::vector<Enemy*> enemies, int frame, int move_animation){
    for(Enemy* e_ptr : enemies){
        draw_enemy(rwindow, e_ptr, frame, move_animation); // zeros are placeholders
    }
}



// draws a grid with the rectangle to a rendertexture and sets this as the texture for the drawable level
void Renderer::make_drawable_level(Level& lv){
    // pass the level argument with existing grid, either from random generation or loaded from file

    if(!_level_texture.create(lv.get_square_size()*10, lv.get_square_size()*10)){ 
        std::cout << "RenderTexture creation failed for level" << std::endl;
    }    
    
    // variables for drawing
    int square_type; 
    Vector2D center_coords;
    int upper_left_corner_x; 
    int upper_left_corner_y;
    sf::Sprite drawable_level_square;

    // from resource handler picks textures for grass and road
    _grass_pic = _rh.get_texture_tile(0);
    _road_pic = _rh.get_texture_tile(1);
    _house_pic = _rh.get_texture_tile(2);

    int counter = 0;
    // takes grid from level
    std::vector<std::vector<Square *>> level_grid = lv.get_grid();

    // goes throw every square and draws road or grass depending on occupied value
    for(auto column : level_grid){
        for(auto square : column){
            square_type = square->get_occupied();
            center_coords = square->get_center();
            // get the upper left corner position of a level grid, position of the graphic objects is taken from the upper left corner
            upper_left_corner_x  = center_coords.x - lv.get_square_size()/2;
            upper_left_corner_y  = center_coords.y - lv.get_square_size()/2;
            // drawable_level_square.setOutlineColor(grey);

            if (counter == 9){
                if(square_type == occupied_type::grass){
                    drawable_level_square.setTexture(_grass_pic);
                } else if(square_type == occupied_type::road) {
                    drawable_level_square.setTexture(_house_pic);
                }
            } else {
                if(square_type == occupied_type::grass){
                    drawable_level_square.setTexture(_grass_pic);
                } else if(square_type == occupied_type::road) {
                    drawable_level_square.setTexture(_road_pic);
                }
            }

            drawable_level_square.setPosition(upper_left_corner_y, upper_left_corner_x);

            drawable_level_square.setScale(2.45 , 2.45);

            _level_texture.draw(drawable_level_square);
            counter++;
        }
        counter = 0;
    }

    // displays whole level
    _level_texture.display();
    _drawable_level.setTexture(_level_texture.getTexture());
}


