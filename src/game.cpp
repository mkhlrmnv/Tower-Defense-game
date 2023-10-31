#include "game.hpp"


void Game::Start(){
    window_.create(sf::VideoMode(resolution_.first, resolution_.second), "Tower Defence");
    while(window_.isOpen()){

        sf::Event event;
        while(window_.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window_.close();
            }
        }
    }
}

void Game::Update(){

}

void Game::Quit(){

}


int main(){
    Game game;
    game.Start();
    auto res = game.GetResolution();
    std::cout << "resolution: " << res.first << "x" << res.second << std::endl;
    return 1;
}