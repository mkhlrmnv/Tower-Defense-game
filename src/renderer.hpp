#ifndef TOWER_DEFENCE_SRC_RENDERER_HPP
#define TOWER_DEFENCE_SRC_RENDERER_HPP


#include "vector2d.hpp"
#include "level.hpp"
#include "object.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "resource_handler.hpp"

#include "attack_types.hpp"

/**
 * @brief Class for creating drawable game objects for window.draw([DRAWABLE GAME OBJECT])
 */
class Renderer{
public:
    /**
     * @brief Construct a new Renderer object
     */
    Renderer();
    /**
     * @brief Destroy the Renderer object
     */
    Renderer(ResourceHandler& rh);
    ~Renderer(){}
    Renderer(const Renderer& ) = delete;
    Renderer operator=(const Renderer&) = delete;

    /**
     * @brief Makes displays current level
     * @param lv level that is displayed
     */
    void make_drawable_level(Level & lv); 
    void make_level_info_texts(int game_resolution, int side_bar_width);
    
    /**
     * @brief draw background
     * @param rwindow windows where background is drawn
     */
    void draw_level(sf::RenderWindow& rwindow);

    /**
     * @brief draw single enemy  
     * @param rwindow window where to draw
     * @param e_ptr pointer to enemy
     * @param frame current frame of animation
     * @param move_animation current frame for enemies move animation (for smoother movement)
     */
    void draw_enemy(sf::RenderWindow& rwindow, Enemy* e_ptr, int frame);
    
    /**
     * @brief draw enemies on from a list
     * @param rwindow window where to draw
     * @param enemies list of enemies
     * @param frame current frame of animation
     * @param move_animation current frame for enemies move animation (for smoother movement)
     */
    void draw_enemies(sf::RenderWindow& rwindow, std::vector< Enemy * > enemies, int frame);

    /**
     * @brief draw single enemy 
     * @param rwindow window where to draw
     * @param t_ptr pointer to tower
     * @param frame current frame of animation
     */
    void draw_tower(sf::RenderWindow& rwindow, Tower* t_ptr, int frame);
    
    /**
     * @brief draw towers on from a list
     * @param rwindow  window where to draw
     * @param towers list of towers
     * @param frame current frame of animation
     */
    void draw_towers(sf::RenderWindow& rwindow, std::vector< Tower * > towers, int frame);

    /**
     * @brief victory screen on GameState::EndScreen
     * @param rwindow  window where to draw
     */
    void draw_end_screen_win(sf::RenderWindow& rwindow);

    /**
     * @brief game over screen on GameState::EndScreen
     * @param rwindow  window where to draw
     */
    void draw_end_screen_lose(sf::RenderWindow& rwindow);


private:
    /**
     * @brief a sprite for drawing grid
     */
    sf::Sprite _drawable_level;

    // a sprite for drawing objects 
    /**
     * @brief a sprite for drawing objects 
     */
    sf::Sprite _drawable_enemy;
    /**
     * @brief a sprite for drawing objects 
     */
    sf::Sprite _drawable_tower; 
    /**
     * @brief a sprite for drawing end screen.
     */
    sf::Sprite _end_screen; 



    /**
     * @brief grids connected as a one RenderedTexture
     */
    sf::RenderTexture _level_texture; 

    /**
     * @brief place holders
     */
    sf::RenderTexture _tower_texture; 
    /**
     * @brief place holders
     */
    sf::RenderTexture _enemy_texture; 

    /**
     * @brief number that scales textures to right size
     * 
     */
    float scale_factor;

    /**
     * @brief for tower texture
     */
    sf::Texture _tower_sprite;
    /**
     * @brief for enemy texture
     */
    sf::Texture _enemy_sprite;

    sf::Texture _grass_pic;
    sf::Texture _road_pic;
    sf::Texture _house_pic;

    /**
     * @brief Scale for towers
     */
    float _scale_factor_tower = 2.5; // Adjust this value as needed
    float _scale_factor_enemy = 1; // TODO: some enemy type depending value

    /**
     * @brief a reference to Resource handler
     */
    ResourceHandler& _rh;
};

#endif 