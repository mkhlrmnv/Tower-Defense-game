#ifndef TOWER_DEFENCE_SRC_GAME
#define TOWER_DEFENCE_SRC_GAME

#include "level.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "renderer.hpp"
#include <random>

#include "basic_enemy.hpp"
#include "basic_tower.hpp"
#include "aoe_tower.hpp"
#include "archer_tower.hpp"
#include "boss_enemy.hpp"
#include "demon_enemy.hpp"
#include "fastboy_enemy.hpp"
#include "fogmage_enemy.hpp"
#include "healer_enemy.hpp"
#include "inferno_enemy.hpp"
#include "repel_tower.hpp"
#include "sceleton_enemy.hpp"
#include "sniper_tower.hpp"
#include "tank_enemy.hpp"

#include "side_menu.hpp"
#include "upgrade.hpp"
#include "main_menu.hpp"
#include "choose_level_menu.hpp"

/**
 * @brief Enum for which kind of level is beeing loaded
 */
namespace LevelSelection{
    enum Choice: int{
        random, load
    };
}

namespace GameState{
    enum State{
        StartMenu, MapMenu, Pause, Round, Victory, GameOver
    };
}


/**
 * @brief A class for running the game. Opens a window in which a game loop handles user input key, updates game state and draws game entities. 
 */
class Game{
public:
    /**
     * @brief Construct a new Game object
     */
    Game();
    /**
     * @brief Destroy the Game object
     */
    ~Game(){}
    Game(const Game& ) = delete;
    Game operator=(const Game&) = delete;

    /**
     * @brief Get the side bar width
     * @return int
     */
    int get_side_bar_width() const;
    /**
     * @brief Get the games resolution
     * @return int 
     */
    int get_game_resolution() const;

    /**
     * @brief Starts the game that loop until window is closed
     */
    void run();

private: 

    /**
     * @brief Opens window 
     */
    void open_window();

    /**
     * @brief Process events in loop:  clicks, button presses
     */
    void process_events();

    /**
     * @brief Update game state in loop: attacks, movement
     */
    void update();

    /**
     * @brief Draws a frame in loop,
     */
    void render();

    /**
     * @brief Starts new round
     */
    void start_round();

    /**
     * @brief Updates all enemies
     * If enemy can attack, it attacks and if not it moves
     */
    void update_enemies();

    /**
     * @brief Updates all towers
     * Attacks if there is enemy in range
     */
    void update_towers();

    int _game_resolution;
    int _side_bar_width;

    sf::RenderWindow _window;

    
    
    /**
    * @brief sf::Time parameter determines the time which is spent in the end screen before reseting to the start menu
    *  
    */
    sf::Time _reset_time = sf::Time::Zero;

    /**
    * @brief sf::Time parameter determines the time which is spent in the end screen before reseting to the start menu
    *  
    */
    sf::Clock _reset_clock;
    

    /**
     * @brief int parameter determines the starting cash for the level
     *  
     */
    int _starting_cash = 500;

    /**
     * @brief int parameter determines the starting lives for the level
     */
    int _starting_lives = 5;

    /**
     * @brief int parameter determines state of the game state:
     * which menu to display, run the game or pause. 
     */
    int _game_state = 0;

    /**
     * @brief int parameter determines how many rounds one must survive to beat the game. 
     */
    int _rounds_to_survive = 30;

    /**
     * @brief Bool parameter if round is over or not
     */
    bool _round_over = true;

    /**
     * @brief Stores difficulty level of current game
     */
    int _difficulty_multiplier = 2;

    /**
     * @brief amount of available enemy types
     * Gets bigger with rounds beeing played
     */
    int _available_types = 1;

    /**
     * @brief Variable for animation phase
     * To know which part of animation to play
     */
    int _animation_phase;

    /**
     * @brief basic amount of money given
     */
    int _basic_money = 50;


    ResourceHandler _rh;
    Renderer _renderer;
    Level _level;
    MainMenu _main_menu;
    ChooseLevelMenu _level_menu;
    SideMenu _side_menu;
    Upgrade _upgrade;
}; 
#endif