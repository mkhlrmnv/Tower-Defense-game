#ifndef TOWER_DEFENCE_SRC_RENDERER_HPP
#define TOWER_DEFENCE_SRC_RENDERER_HPP


#include <vector2d.hpp>
#include <level.hpp>
#include <object.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


/* Class for creating drawable game objects for window.draw([DRAWABLE GAME OBJECT]) in game class.*/
/* TODO: Make another class for loading and storing textures, in some data structure, for example 2d array or similar: 
    texture = Textures.get_texture(object_type, object_state) */

class Renderer{
public:

    Renderer(){}
    ~Renderer(){}
    Renderer(const Renderer& ) = delete;
    Renderer operator=(const Renderer&) = delete;

    // call at the beginning of the game
    void make_drawable_level(Level & lv);
    void make_drawable_object_textures(); // place holder, TODO: remove after handling textures

    //void make_drawable_buttons()
    
    // draw background
    void draw_level(sf::RenderWindow& rwindow);


    // draw single enemy  
    void draw_enemy(sf::RenderWindow& rwindow, int object_type, int object_state, Vector2D location); // TODO: implement the choice of correct texture with ongoing action and object type
    
    // draw enemies on from a list
    void draw_enemies(sf::RenderWindow& rwindow, std::vector< Enemy * > enemies); // TODO: Test this, remove last argument with real textures 

    // draw single enemy 
    void draw_tower(sf::RenderWindow& rwindow, int object_type, int object_state, Vector2D location); // TODO: implement the choice of correct texture with ongoing action and object type
    
    // draw towers on from a list
    void draw_towers(sf::RenderWindow& rwindow, std::vector< Tower * > towers); // TODO: Test this, remove last argument with real textures 

    //void draw_hp(hp);
    //void draw_cash(cash);
    //void draw_round_count(round_count);

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



// Textures _textures //  some tree like data structure for different attacks of objects

};

#endif 