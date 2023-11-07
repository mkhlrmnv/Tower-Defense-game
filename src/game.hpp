#ifndef TOWER_DEFENCE_SRC_GAME
#define TOWER_DEFENCE_SRC_GAME

#include <level.hpp>
#include <enemy.hpp>
#include <tower.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <renderer.hpp>


namespace LevelSelection{
    enum Choice: int{
        random, load
    };
}

class Game{
public:
    
    Game();

    // call from main
    void run();
    
private: 

    // make the level from chosen style: random or load from file
    int generate_chosen_level_style(int chosen_lv);

    // open window
    void open_window();

    // process events:  clicks, button presses, key
    void process_events();

    // update game state: attacks, movement
    void update();

    // render graphics
    void render();

    Vector2D some_pos;

    int _game_resolution;
    int _side_bar_width;

    sf::RenderWindow _window;

    Renderer _renderer;
    Level _level;

}; 
#endif