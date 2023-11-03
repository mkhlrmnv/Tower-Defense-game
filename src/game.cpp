#include "game.hpp"


Game::Game():_game_resolution(800), _side_bar_width(200), _window(){}

// window stuff
void Game::open_window(){
    _window.create(sf::VideoMode(_game_resolution + _side_bar_width, _game_resolution ), "Tower Defence");
    _window.setPosition(sf::Vector2i(200, 0));
}


void Game::run(){

    open_window();

    while(_window.isOpen()){
        process_events();
        update();
        render();
    }

}

void Game::update(){

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
    // draw objects
    _window.display();

}


int main(){
    Game game;
    game.run();
    return 1;
    
}