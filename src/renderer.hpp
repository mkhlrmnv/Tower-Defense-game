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


/* Class for creating drawable game objects for window.draw([DRAWABLE GAME OBJECT]) .*/
/* TODO: Make another class for loading and storing textures, in some data structure, for example 2d array or similar: 
    texture = Textures.get_texture(object_type, object_state), where on object_state to choose between shoot left/right, die etc.*/

class Renderer{
public:

    Renderer();
    ~Renderer(){}
    Renderer(const Renderer& ) = delete;
    Renderer operator=(const Renderer&) = delete;

    // call at the beginning of the game
    void make_drawable_level(Level & lv); 
    void make_level_info_texts(int game_resolution, int side_bar_width);
    
    // draw background
    void draw_level(sf::RenderWindow& rwindow);

    // draw single enemy  
    void draw_enemy(sf::RenderWindow& rwindow, Enemy* e_ptr, int frame); // TODO: implement the choice of correct texture with obn and object type
    
    // draw enemies on from a list
    void draw_enemies(sf::RenderWindow& rwindow, std::vector< Enemy * > enemies, int frame); // TODO: remove last argument with real textures 

    // draw single enemy 
    void draw_tower(sf::RenderWindow& rwindow, Tower* t_ptr, int frame); // TODO: implement the choice of correct texture with object state and object type
    
    // draw towers on from a list
    void draw_towers(sf::RenderWindow& rwindow, std::vector< Tower * > towers, int frame); // TODO: remove last argument with real textures 


    // draw texts 
private:
    // a sprite for drawing grid
    sf::Sprite _drawable_level;

    // a sprite for drawing objects 
    sf::Sprite _drawable_enemy;
    sf::Sprite _drawable_tower; 

    // grids connected as a one RenderedTexture
    sf::RenderTexture _level_texture; 

    // place holders
    sf::RenderTexture _tower_texture; 
    sf::RenderTexture _enemy_texture; 

    float scale_factor; // number that scales textures to right size

    sf::Texture _tower_sprite; // for tower texture
    sf::Texture _enemy_sprite; // for enemy texture

    sf::Texture _grass_pic;
    sf::Texture _road_pic;
    sf::Texture _house_pic;

    float _scale_factor_tower = 2.5; // Adjust this value as needed
    float _scale_factor_enemy = 1; // TODO: some enemy type depending value


    // Resource handler
    ResourceHandler _rh;
};

#endif 