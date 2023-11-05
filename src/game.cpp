#include "game.hpp"


Game::Game(): _game_resolution(800), _side_bar_width(200), _window(), _level(800, 250, 50){}

void Game::print_lv(){
    _level.make_grid();
    _level.print_map();
    _level.randomly_generate();
    _level.print_map();
    std::vector<std::vector<Square *>> grid = _level.get_grid();

}   

void Game::display_level(){

    _level.make_grid();
    
    if(_level.read_file("../maps/example_map.txt")==-1){
        std::cout << "read failed" <<std::endl;
    }else{
        std::cout << "read successfull" <<std::endl;
        }
    
    //_level.randomly_generate();
    _level.print_map();
    
    
    int square_type; 
    Vector2D center_coords;
    int upper_left_corner_x; 
    int upper_left_corner_y;

    // fill the window with the grid 
    std::vector<std::vector<Square *>> level_grid = _level.get_grid();
    for(auto column : level_grid){
        for(auto square : column){
            square_type = square->get_occupied();
            center_coords = square->get_center();
            // drawing the graphic objects starts from upper left corner
            upper_left_corner_x  = center_coords.x - _game_resolution/(2*10);
            upper_left_corner_y  = center_coords.y - _game_resolution/(2*10);
            // TODO: change to sprite with textures
            sf::Color green = sf::Color(0, 128, 0);
            sf::Color grey = sf::Color(128, 128, 128);
            sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(_game_resolution/10,_game_resolution/10));
            rect.setPosition(upper_left_corner_y, upper_left_corner_x);
            
            if(square_type == occupied_type::grass){
                rect.setFillColor(green);
            }
            else if(square_type == occupied_type::road){
                rect.setFillColor(grey);
            }
            _graphics.push_back(rect);
        }
    }
}

// window
void Game::open_window(){
    _window.create(sf::VideoMode(_game_resolution + _side_bar_width, _game_resolution ), "Tower Defence");
    _window.setPosition(sf::Vector2i(200, 0));
}


void Game::run(){

    open_window();
    display_level();

     
    while(_window.isOpen()){
        process_events();
        update();
        render();
    }

}

void Game::update(){
    // game logic:  attacks, movements,  etc here
}

void Game::process_events(){

    sf::Event event;
    while(_window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            _window.close();
        }
    }

}

void Game::render(){
    _window.clear();
     
    for(auto square_graphic : _graphics){
        _window.draw(square_graphic);
    }
    _window.display();

}