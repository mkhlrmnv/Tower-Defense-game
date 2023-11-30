#ifndef TOWER_DEFENCE_SRC_RESOURCE_HANDLER
#define TOWER_DEFENCE_SRC_RESOURCE_HANDLER

#include<SFML/Graphics.hpp>
#include<memory>
#include "attack_types.hpp"

/* 
    loads ALL textures and gives them as pointers.
    needs to be created in game class, pass as reference
*/

namespace TowerAttributes{
    enum Atr{
        HP, DMG, RNG, ATKSPD, MONEY, ROUND
    };
};

class ResourceHandler{

public:
    ResourceHandler(){load_all_textures();}

    // functions to get pointers to textures by type of object
    sf::Texture& get_texture_tower(int type);
    sf::Texture& get_texture_enemy(int type);
    sf::Texture& get_texture_tile(int type);
    sf::Font& get_font();
    
    // function to access tower attributes;
    int  get_tower_info(int tower_type, int attr_type);
    const std::string& get_tower_name(int type);

    // function to access attribute textures
    // use heart, and money in as cash and lives
    sf::Texture& get_texture_attribute(int type);
    
private:

    void load_all_textures();

    // load functions for all textures
    // some image.png -> sf::Texture
    void load_texture_tower(int type, const std::string& filename);
    void load_texture_enemy(int type, const std::string& filename);
    void load_texture_tile(int type, const std::string& filename);
    void load_texture_attribute(int type, const std::string& filename);

    void load_texture_menu(int type, const std::string& filename);
    void load_font();

    void fill_attribute_map(int type, std::array<int, 5> attributes);
    void fill_tower_attributes_map();
    void fill_tower_names_map();

    // place holders for all textures
    // object_type -->  texture_ptr
    std::map<int, std::shared_ptr<sf::Texture>> _towers_textures_ptr_map;
    std::map<int, std::shared_ptr<sf::Texture>> _enemies_textures_ptr_map;
    std::map<int, std::shared_ptr<sf::Texture>> _tiles_textures_ptr_map;
    std::map<int, std::shared_ptr<sf::Texture>> _menu_textures_ptr_map;


    // holds info for towers
    // Tower_type --> attribute list
    std::map<int, std::shared_ptr<std::map<int, int>>> _tower_attributes;
    std::map<int, const std::string> _tower_names;
    sf::Font _font;

    //menu graphics;
    std::map<int, std::shared_ptr<sf::Texture>> _attr_textures_ptr_map;

};


#endif