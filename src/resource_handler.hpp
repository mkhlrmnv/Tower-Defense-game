#ifndef TOWER_DEFENCE_SRC_RESOURCE_HANDLER
#define TOWER_DEFENCE_SRC_RESOURCE_HANDLER

#include<SFML/Graphics.hpp>
#include<memory>
#include "attack_types.hpp"

/* 
    loads ALL textures and gives them as pointers.
    needs to be created in game class, pass as reference
*/

// 2. TODO: Automate loading somehow

class ResourceHandler{

public:
    
    // 
    ResourceHandler(){load_all_textures(); load_font();}
    sf::Texture& get_texture_tower(int type);
    sf::Texture& get_texture_enemy(int type);
    sf::Texture& get_texture_tile(int type);
    sf::Font& get_font();
    
private:

    void load_all_textures();

    // someimage.png -> sf::Texture
    void load_texture_tower(int type, const std::string& filename);

    void load_texture_enemy(int type, const std::string& filename);

    void load_texture_tile(int type, const std::string& filename);

    void load_font();

    sf::Font _font;

    std::map<int, std::shared_ptr<sf::Texture>> _towers_textures_ptr_map;

    std::map<int, std::shared_ptr<sf::Texture>> _enemies_textures_ptr_map;

    std::map<int, std::shared_ptr<sf::Texture>> _tiles_textures_ptr_map;

    // object_type, state, -->  texture_ptr
    std::map<std::pair<int, int>, std::shared_ptr<sf::Texture>> _texture_ptr_map;

    //
};


#endif