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

#include "side_menu.hpp"

#include "side_menu.hpp"
#include "upgrade.hpp"
#include "main_menu.hpp"
#include "choose_level_menu.hpp"



/**
 * @brief enum for game states.
 * 
 */
namespace GameState{
    enum State{
        StartMenu, MapMenu, Pause, Round, Victory, GameOver
    };
}

namespace GameState{
    enum State{
        StartMenu, MapMenu, Pause, Round, Endgame
    };
}

/**
 * @brief A class for running the game. Opens a window in which a game loop handles user inputs, updates game state and draws game entities.
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

    ResourceHandler _rh;
    Renderer _renderer;

    /**
     * @brief a class to represent the level and implement game logic.
     * 
     */
    Level _level;
    SideMenu _side_menu;
    Upgrade _upgrade;

    /**
     * @brief a class to select either random or existing maps.
     * 
     */
    MainMenu _main_menu;

    /**
     * @brief a class to select from six existing maps.
     * 
     */
    ChooseLevelMenu _level_menu;

    /**
     * @brief a class to implement the side menu: purchase towers, display level info, start the round.
     * 
     */
    SideMenu _side_menu;

    /**
     * @brief a class to implement the upgrade feature for the towers. 
     * 
     */
    Upgrade _upgrade;
}; 
#endif