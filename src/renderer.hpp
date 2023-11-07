#ifndef TOWER_DEFENCE_SRC_RENDERER_HPP
#define TOWER_DEFENCE_SRC_RENDERER_HPP


#include <vector2d.hpp>
#include <level.hpp>
#include <object.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


/* Class for creating drawable game objects for window.draw([DRAWABLE GAME OBJECT]) in game class.
    TODO: Make another class for loading and storing textures, in some data structure, for example 2d array or similar: 
    texture = Textures.get_texture(object_type, object_state)
*/
class Renderer{


public:
    Renderer(){}


    // call at the beginning of the game
    void make_drawable_level(Level & lv);
    void make_drawable_object_textures(); // place holder, TODO: remove after handling textures
    //void make_drawable_towers(//);
    //void make_drawable_buttons()

    
    // draw background
    void draw_level(sf::RenderWindow& rwindow);


    // draw single object   
    void draw_object(sf::RenderWindow& rwindow, int object_type, int object_state, Vector2D location); // TODO: implement the choice of correct texture with ongoing action and object type
    
    // draw objects on from a list
    void draw_objects(sf::RenderWindow& rwindow, std::vector<Object*> objs, int enemy_or_tower); // TODO: Test this, remove last argument with real textures 


    //void draw_hp(hp);
    //void draw_cash(cash);
    //void draw_round_count(round_count);
    //void draw_();

private:

// a sprite for drawing grid
sf::Sprite _drawable_level;

// a sprite for drawing objects 
sf::Sprite _drawable_object; 

// grids connected as a one RenderedTexture
sf::RenderTexture _level_texture; 

// place holders
sf::RenderTexture _tower_texture; 
sf::RenderTexture _enemy_texture; 



// Textures _textures //  some tree like data structure for different attacks of objects

};

#endif 