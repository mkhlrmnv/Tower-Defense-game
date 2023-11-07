#ifndef TOWER_DEFENCE_SRC_RENDERER_HPP
#define TOWER_DEFENCE_SRC_RENDERER_HPP


#include <vector2d.hpp>
#include <level.hpp>
#include <object.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


/* Class for creating drawable game objects for window.draw([DRAWABLE GAME OBJECT]) in game class.
    TODO: Make another class for loading and storing textures, in some nice tree structure
*/
class Renderer{


public:
    Renderer(){}
    // call at the beginning of the game
    void make_drawable_level(Level & lv);
    void make_drawable_object_textures(); // place holder, TODO: remove after handling textures
    //void make_drawable_towers(//);
    //void make_drawable_buttons()

    // call from window.draw()
    
    // draw background
    void draw_level(sf::RenderWindow& rwindow);


    /* 
        TODO: choose correct texture with ongoing action and object type
    */
    void draw_object(sf::RenderWindow& rwindow, int type, int ongoing_action, Vector2D location);

    void draw_objects(sf::RenderWindow& rwindow, std::vector<Object*> objs, int road_or_tower);

    void draw_objects_from_level(sf::RenderWindow& rwindow, Level& lv);

    //void draw_hp(hp);
    //void draw_cash(cash);
    //void draw_round_count(round_count);
    //void draw_();

private:

// 
sf::Sprite _drawable_level;

// a sprite for drawing objects 
sf::Sprite _drawable_object; 

// grids connected as a one RenderedTexture
sf::RenderTexture _level_texture; 

sf::RenderTexture _tower_texture; // place holder 
sf::RenderTexture _enemy_texture; // place holder



// Textures _textures //  some tree like data structure for different attacks of objects

};

#endif 