#ifndef TOWER_DEFENCE_SRC_GAME
#define TOWER_DEFENCE_SRC_GAME

#include<utility>
#include <SFML/Window.hpp>
#include <iostream>


class Game{
public:
    
    Game():resolution_({1000, 1000}){}
    
    std::pair<int, int>GetResolution(){return resolution_; };
    
    void Start();
    void Update();
    void Quit();

private:
    std::pair<int, int> resolution_;
    sf::Window window_;
    // sometype  graphics_;
    // sometype map_;
}; 
#endif