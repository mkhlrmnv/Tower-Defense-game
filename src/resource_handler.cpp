#include "resource_handler.hpp"
#include "constants.hpp"



sf::Texture& ResourceHandler::get_texture(int object_type, int object_state){
    std::pair<int, int> key = {object_type, object_state};
    return *(_texture_ptr_map[key]);
}

sf::Font& ResourceHandler::get_font(){
    return _font;
}

void ResourceHandler::load_texture(int object_type, int object_state, const std::string& filename){
    std::shared_ptr<sf::Texture> tx = std::make_shared<sf::Texture>();
    tx->loadFromFile(filename);
    std::pair<int, int> key = {object_type, object_state};
    _texture_ptr_map[key] = tx;
}

void ResourceHandler::load_font(){
    _font.loadFromFile(Constants::path_to_project + "assets/fonts/Ubuntu-R.ttf");
}

void ResourceHandler::load_all_textures(){
    load_texture(ObjectTextureTypes::ArcherTower, 0, Constants::path_to_project + "assets/textures/ArcherTower/ArcherTower_Right.png");
}