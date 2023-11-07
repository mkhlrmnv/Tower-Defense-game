#include "game.hpp"


Game::Game(): _game_resolution(800), _side_bar_width(300), _window(), _level(800, 250, 50), _renderer(), some_pos(200,200){
}

int Game::generate_chosen_level_style(int chosen_lv){
    // TODO: maybe do this on level class?
    // TODO: add choosing feature
     _level.make_grid();
    if(chosen_lv == LevelSelection::random){
        if(!_level.randomly_generate()){
        std::cout << "random level generation failed" <<std::endl;
        return 0;
    }else{
        std::cout << "random level generation successful" <<std::endl;
        }
    }else if(chosen_lv == LevelSelection::load){
        if(_level.read_file("../maps/example_map.txt")==-1){
            std::cout << "level file read failed" <<std::endl;
            return 0;
        }else{
            std::cout << "level file read successfull" <<std::endl;
        }
    }
    return 1;
}

void Game::open_window(){
    _window.create(sf::VideoMode(_game_resolution + _side_bar_width, _game_resolution ), "Tower Defence");
    _window.setPosition(sf::Vector2i(200, 0));
}

void Game::run(){

    open_window();
    generate_chosen_level_style(LevelSelection::load); 
    _renderer.make_drawable_level(_level);
    _renderer.make_drawable_object_textures();

    while(_window.isOpen()){
        process_events();
        update();
        render();
    }

}

void Game::update(){
    // update game state: buys, attacks, movements,  etc here
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
    _renderer.draw_level(_window);
    _renderer.draw_object(_window, 2, 0, some_pos);
    _window.display();

}