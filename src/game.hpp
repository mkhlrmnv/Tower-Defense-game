#ifndef TOWER_DEFENCE_SRC_GAME
#define TOWER_DEFENCE_SRC_GAME

#include<utility>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


class Game{
public:
    
    Game();
    void run();

private: 
    void open_window();
    void process_events();
    void update();
    void render();

private:
    int _game_resolution;
    int _side_bar_width;
    sf::RenderWindow _window;
    // sometype  _graphics;
    // sometype _level;
}; 
#endif