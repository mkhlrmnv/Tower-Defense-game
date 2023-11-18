#ifndef TOWER_DEFENCE_SRC_GAME
#define TOWER_DEFENCE_SRC_GAME

#include <level.hpp>
//#include "object.hpp"
// #include "tower.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <renderer.hpp>
#include <random>

#include "basic_enemy.hpp"
#include "basic_tower.hpp"

namespace LevelSelection{
    enum Choice: int{
        random, load
    };
}


/* 

A class for running the game. Opens a window in which a game loop handles user input key, updates game state and draws game entities. 
Currently only draws place holder game entities. 

check SFML Game Development.pdf from google.

*/

class Game{
public:
    
    Game();
    ~Game(){}
    Game(const Game& ) = delete;
    Game operator=(const Game&) = delete;

    int get_side_bar_width() const;
    int get_game_resolution() const;

    // call from main, runs the game loop until a the window is closed, 
    void run();

    
    
private: 

    // makes the grid for the level and then fills it according to the chosen style: random or load from file
    int generate_chosen_level_style(int chosen_lv);

    // open window
    void open_window();

    // process events in loop:  clicks, button presses
    void process_events();

    // update game state in loop: attacks, movement
    void update();

    // draws a frame in loop,
    void render();

    void start_round();

    // for testing only
    Vector2D some_pos; 

    int _game_resolution;
    int _side_bar_width;

    sf::RenderWindow _window;

    Renderer _renderer;
    Level _level;

    bool round_over = false;

    

}; 
#endif