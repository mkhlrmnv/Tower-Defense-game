#include "resource_handler.hpp"


// returns pointer to spread sheet
sf::Texture& ResourceHandler::get_texture_tower(int type){
    return *(_towers_textures_ptr_map[type]);
}

// returns pointer to spread sheet
sf::Texture& ResourceHandler::get_texture_enemy(int type){
    return *(_enemies_textures_ptr_map[type]);
}

// returns pointer to texture
sf::Texture& ResourceHandler::get_texture_tile(int type){
    return *(_tiles_textures_ptr_map[type]);
}

// returns pointer to font
sf::Font& ResourceHandler::get_font(){
    return _font;
}

const std::array<int, 5>& ResourceHandler::get_tower_info(int type){
    return _tower_attributes[type];
}

const std::string& ResourceHandler::get_tower_name(int type){
    return _tower_names[type];
}


// load towers spread sheet and puts it into placeholder
void ResourceHandler::load_texture_tower(int type, const std::string& filename){
    std::shared_ptr<sf::Texture> tx = std::make_shared<sf::Texture>();
    tx->loadFromFile(filename);
    _towers_textures_ptr_map[type] = tx;
}

// load enemy spread sheet and puts it into placeholder
void ResourceHandler::load_texture_enemy(int type, const std::string& filename){
    std::shared_ptr<sf::Texture> tx = std::make_shared<sf::Texture>();
    tx->loadFromFile(filename);
    _enemies_textures_ptr_map[type] = tx;
}

// load tile texture and puts it into placeholder
void ResourceHandler::load_texture_tile(int type, const std::string& filename){
    std::shared_ptr<sf::Texture> tx = std::make_shared<sf::Texture>();
    tx->loadFromFile(filename);
    _tiles_textures_ptr_map[type] = tx;
}

// load font and puts it into placeholder
void ResourceHandler::load_font(){
    _font.loadFromFile("../assets/fonts/Ubuntu-R.ttf");
}

// loads all textures that game will use
void ResourceHandler::load_all_textures(){
    // Enemies
    load_texture_enemy(ObjectTypes::NoobSkeleton_NoAttack, "../assets/textures/VERY_LITTLE_ENEMIES/VERY_LITTLE_NoobSkeleton.png");
    load_texture_enemy(ObjectTypes::NoobDemon_CanAttack, "../assets/textures/VERY_LITTLE_ENEMIES/VERY_LITTLE_NoobDemon.png");
    load_texture_enemy(ObjectTypes::FastBoy, "../assets/textures/VERY_LITTLE_ENEMIES/VERY_LITTLE_FastBoy.png");
    load_texture_enemy(ObjectTypes::FogMage, "../assets/textures/VERY_LITTLE_ENEMIES/VERY_LITTLE_FogMage.png");
    load_texture_enemy(ObjectTypes::HealerPriest, "../assets/textures/VERY_LITTLE_ENEMIES/VERY_LITTLE_HealerPriest.png");
    load_texture_enemy(ObjectTypes::InfernoMage, "../assets/textures/VERY_LITTLE_ENEMIES/VERY_LITTLE_InfernoMage.png");
    load_texture_enemy(ObjectTypes::TankOrc, "../assets/textures/VERY_LITTLE_ENEMIES/VERY_LITTLE_TankOrc.png");
    load_texture_enemy(ObjectTypes::BossKnight, "../assets/textures/VERY_LITTLE_ENEMIES/VERY_LITTLE_BossKnight.png");

    // Towers
    load_texture_tower(ObjectTypes::ArcherTower, "../assets/textures/VERY_LITTLE_TOWERS/VERY_LITTLE_ArcherTower.png");
    load_texture_tower(ObjectTypes::AoeTower, "../assets/textures/VERY_LITTLE_TOWERS/VERY_LITTLE_AoeTower.png");
    load_texture_tower(ObjectTypes::MudMageTower, "../assets/textures/VERY_LITTLE_TOWERS/VERY_LITTLE_MudMage.png");
    load_texture_tower(ObjectTypes::RepelMageTower, "../assets/textures/VERY_LITTLE_TOWERS/VERY_LITTLE_RepelMage.png");
    load_texture_tower(ObjectTypes::SniperTower, "../assets/textures/VERY_LITTLE_TOWERS/VERY_LITTLE_SniperTower.png");
    load_texture_tower(ObjectTypes::WaterMageTower, "../assets/textures/VERY_LITTLE_TOWERS/VERY_LITTLE_WaterMage.png");

    // Tiles
    load_texture_tile(0, "../assets/textures/VERY_LITTLE_GRASSTILE.png");
    load_texture_tile(1, "../assets/textures/VERY_LITTLE_ROADTILE.png");
    load_texture_tile(2, "../assets/textures/VerySmallSize_32x32/VerySmall_Tiles_32x32/House_32x32.png");

    // Font 
    load_font();
}

void ResourceHandler::fill_tower_attributes(){
    
    // hp, dmg, rng, atk_spd, price
    _tower_attributes[ObjectTypes::AoeTower]= {30, 10, 100, 2, 100};
    _tower_attributes[ObjectTypes::ArcherTower]= {30, 10, 100, 3, 100};
    _tower_attributes[ObjectTypes::SniperTower]= {10, 30, 1000, 1, 150};
    _tower_attributes[ObjectTypes::RepelMageTower]= {30, 5, 120, 1, 180};

}

void ResourceHandler::fill_tower_names(){
    _tower_names.emplace(ObjectTypes::AoeTower, "Aoe") ;
    _tower_names.emplace(ObjectTypes::ArcherTower , "Archer");
    _tower_names.emplace(ObjectTypes::SniperTower , "Sniper");
    _tower_names.emplace(ObjectTypes::RepelMageTower , "Repel Mage");

}