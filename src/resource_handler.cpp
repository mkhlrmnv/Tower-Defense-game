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

sf::Texture& ResourceHandler::get_texture_attribute(int type){
    return *(_attr_textures_ptr_map[type]);
}

// returns pointer to font
sf::Font& ResourceHandler::get_font(){
    return _font;
}

std::array<int, 5>& ResourceHandler::get_tower_info(int type){
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

void ResourceHandler::load_texture_attribute(int type, const std::string& filename){
    std::shared_ptr<sf::Texture> tx = std::make_shared<sf::Texture>();
    tx->loadFromFile(filename);
    _attr_textures_ptr_map[type] = tx;
};

// load font and puts it into placeholder
void ResourceHandler::load_font(){
    
    if(!_font.loadFromFile("/home/klind/tower_defence/assets/fonts/Ubuntu-R.ttf")){
        std::cout << "failed to load font" << std::endl;
    }
}

// loads all textures that game will use
void ResourceHandler::load_all_textures(){
    // Enemies
    load_texture_enemy(ObjectTypes::NoobSkeleton_NoAttack, "../assets/textures/VerySmallSize_32x32/VerySmall_Enemies_32x32/Right/NoobSkeleton_Right.png");
    load_texture_enemy(ObjectTypes::NoobDemon_CanAttack, "../assets/textures/VerySmallSize_32x32/VerySmall_Enemies_32x32/Right/NoobDemon_Right.png");
    load_texture_enemy(ObjectTypes::FastBoy, "../assets/textures/VerySmallSize_32x32/VerySmall_Enemies_32x32/Right/FastBoy_Right.png");
    load_texture_enemy(ObjectTypes::FogMage, "../assets/textures/VerySmallSize_32x32/VerySmall_Enemies_32x32/Right/FogMage_Right.png");
    load_texture_enemy(ObjectTypes::HealerPriest, "../assets/textures/VerySmallSize_32x32/VerySmall_Enemies_32x32/Right/HealerPriest_Right.png");
    load_texture_enemy(ObjectTypes::InfernoMage, "../assets/textures/VerySmallSize_32x32/VerySmall_Enemies_32x32/Right/InfernoMage_Right.png");
    load_texture_enemy(ObjectTypes::TankOrc, "../assets/textures/VerySmallSize_32x32/VerySmall_Enemies_32x32/Right/TankOrc_Right.png");
    load_texture_enemy(ObjectTypes::BossKnight, "../assets/textures/VerySmallSize_32x32/VerySmall_Enemies_32x32/Right/BossKnight_Right.png");

    // Towers
    load_texture_tower(ObjectTypes::ArcherTower, "../assets/textures/VerySmallSize_32x32/VerySmall_Towers_32x32/Right/ArcherTower_Right.png");
    load_texture_tower(ObjectTypes::AoeTower, "../assets/textures/VerySmallSize_32x32/VerySmall_Towers_32x32/Right/AoeTower_Right.png");
    load_texture_tower(ObjectTypes::MudMageTower, "../assets/textures/VerySmallSize_32x32/VerySmall_Towers_32x32/Right/MudMage_Right.png");
    load_texture_tower(ObjectTypes::RepelMageTower, "../assets/textures/VerySmallSize_32x32/VerySmall_Towers_32x32/Right/RepelMage_Right.png");
    load_texture_tower(ObjectTypes::SniperTower, "../assets/textures/VerySmallSize_32x32/VerySmall_Towers_32x32/Right/SniperTower_Right.png");
    load_texture_tower(ObjectTypes::WaterMageTower, "../assets/textures/VerySmallSize_32x32/VerySmall_Towers_32x32/Right/WaterMage_Right.png");

    // Tiles
    load_texture_tile(0, "../assets/textures/VERY_LITTLE_GRASSTILE.png");
    load_texture_tile(1, "../assets/textures/VERY_LITTLE_ROADTILE.png");

    //Attributes 
    load_texture_attribute(TowerAttributes::ATKSPD, "../assets/textures/Attributes/Attack_Speed.png");
    load_texture_attribute(TowerAttributes::HP,    "../assets/textures/Attributes/Health.png");
    load_texture_attribute(TowerAttributes::MONEY, "../assets/textures/Attributes/Money.png");
    load_texture_attribute(TowerAttributes::RNG,   "../assets/textures/Attributes/Range.png");
    // load_texture_attributes(TowerAttributes::DMG,   "../assets/textures/Attributes/Attack_Speed.png"); TODO: make image for damge


    // Font 
    load_font();
    fill_tower_attributes();
    fill_tower_names();
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