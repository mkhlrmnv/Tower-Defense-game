#ifndef TOWER_DEFENCE_SRC_RESOURCE_HANDLER
#define TOWER_DEFENCE_SRC_RESOURCE_HANDLER

#include<SFML/Graphics.hpp>
#include<memory>
#include "attack_types.hpp"

/* 
    loads ALL textures and gives them as pointers.
    needs to be created in game class, pass as reference
*/

class ResourceHandler{

public:
    ResourceHandler(){load_all_textures(); load_font();}

    // functions to get pointers to textures by type of object
    sf::Texture& get_texture_tower(int type);
    sf::Texture& get_texture_enemy(int type);
    sf::Texture& get_texture_tile(int type);
    sf::Font& get_font();
    
private:

    void load_all_textures();

    // load functions for all textures
    // someimage.png -> sf::Texture
    void load_texture_tower(int type, const std::string& filename);
    void load_texture_enemy(int type, const std::string& filename);
    void load_texture_tile(int type, const std::string& filename);
    void load_font();

    // place holders for all textures
    // object_type -->  texture_ptr
    std::map<int, std::shared_ptr<sf::Texture>> _towers_textures_ptr_map;
    std::map<int, std::shared_ptr<sf::Texture>> _enemies_textures_ptr_map;
    std::map<int, std::shared_ptr<sf::Texture>> _tiles_textures_ptr_map;
    sf::Font _font;
};


#endif