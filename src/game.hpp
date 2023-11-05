#ifndef TOWER_DEFENCE_SRC_GAME
#define TOWER_DEFENCE_SRC_GAME

#include<level.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


class Game{
public:
    
    Game();

    // 
    void run();
    
    // for testing display level
    void print_lv();


private: 

    // draw the level grid according occupied type of square
    void display_level();

    // open window
    void open_window();

    // process events:  clicks, button presses, key
    void process_events();

    // update game state: attacks, movement
    void update();

    // render graphics
    void render();

private:
    int _game_resolution;
    int _side_bar_width;
    sf::RenderWindow _window;
    std::vector<sf::RectangleShape> _graphics;
    Level _level;

}; 
#endif