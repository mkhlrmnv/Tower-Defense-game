#ifndef TOWER_DEFENCE_SRC_RENDERER_HPP
#define TOWER_DEFENCE_SRC_RENDERER_HPP



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
    void make_drawable_level(const Level & lv);
    //void make_drawable_enemies();
    //void make_drawable_towers(//);
    //void make_drawable_buttons()

    // call from window.draw()
    
    // draw background
    void draw_level(sf::RenderWindow& rwindow);

    //void draw_enemy(type, ongoing_action, location);
    
    //void draw_tower(type, ongoing_action, location);

    //void draw_hp(hp);
    //void draw_cash(cash);
    //void draw_round_count(round_count);
    //void draw_();

private:

// 
sf::Sprite _drawable_level; 

// grids connected as a one RenderedTexture
sf::RenderTexture _level_texture;  

// Textures _textures //  some tree like data structure for different attacks of objects

};

#endif 