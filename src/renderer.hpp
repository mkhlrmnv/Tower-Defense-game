#ifndef TOWER_DEFENCE_SRC_RENDERER_HPP
#define TOWER_DEFENCE_SRC_RENDERER_HPP


#include "vector2d.hpp"
#include "level.hpp"
#include "object.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


/* Class for creating drawable game objects for window.draw([DRAWABLE GAME OBJECT]) .*/
/* TODO: Make another class for loading and storing textures, in some data structure, for example 2d array or similar: 
    texture = Textures.get_texture(object_type, object_state), where on object_state to choose between shoot left/right, die etc.*/

class Renderer{
public:

    Renderer(){}
    ~Renderer(){}
    Renderer(const Renderer& ) = delete;
    Renderer operator=(const Renderer&) = delete;

    // call at the beginning of the game
    void make_drawable_level(Level & lv); // TODO: add real textures for grid squares road and grass
    void make_drawable_object_textures(); // place holder, TODO: remove after handling textures
    void make_level_info_texts(int game_resolution, int side_bar_width);

    //void make_drawable_buttons()
    
    // draw background
    void draw_level(sf::RenderWindow& rwindow);


    // draw single enemy  
    void draw_enemy(sf::RenderWindow& rwindow, int object_type, int object_state, Vector2D location); // TODO: implement the choice of correct texture with obn and object type
    
    // draw enemies on from a list
    void draw_enemies(sf::RenderWindow& rwindow, std::vector< Enemy * > enemies); // TODO: remove last argument with real textures 

    // draw single enemy 
    void draw_tower(sf::RenderWindow& rwindow, int object_type, int object_state, Vector2D location); // TODO: implement the choice of correct texture with object state and object type
    
    // draw towers on from a list
    void draw_towers(sf::RenderWindow& rwindow, std::vector< Tower * > towers); // TODO: remove last argument with real textures 


    // draw texts 
    void draw_cash(sf::RenderWindow& rwindow, int cash);
    void draw_lives(sf::RenderWindow& rwindow, int lives);
    void draw_round_count(sf::RenderWindow& rwindow, int round_count);


    void load_font(); // TODO: move this to asset/texture handler

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

sf::Texture _tower_pic; // for tower texture
sf::Texture _enemy_pic; // for enemy texture

int _position_align = 40;

float _scale_factor = 0.05; // Adjust this value as needed

std::string _archer_tower_file = "/Users/mkhlrmnv/Desktop/cpp_project/tower-defence/assets/textures/ArcherTower/ArcherTower_Right.png";
std::string _tank_orc_file = "/Users/mkhlrmnv/Desktop/cpp_project/tower-defence/assets/textures/TankOrc/TankOrc.png";

sf::Font _font;
sf::Text _round_count_text;
sf::Text _cash_text;
sf::Text _lives_text;


// Textures _textures //  some tree like data structure for different object state of objects

};

#endif 