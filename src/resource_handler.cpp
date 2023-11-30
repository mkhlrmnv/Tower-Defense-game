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

int ResourceHandler::get_tower_info(int tower_type, int attr_type){
    return _tower_attributes[tower_type]->at(attr_type);
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

    //std::string filename = "../assets/fonts/Ubuntu-R.ttf";
    std::string filename = "../assets/fonts/PixeloidMono-d94EV.ttf";


    
    if(!_font.loadFromFile(filename)){
        std::cout << "failed to load font" << std::endl;
    }
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

    //Attributes 
    load_texture_attribute(TowerAttributes::ATKSPD, "../assets/textures/Attributes/Attack_Speed.png");
    load_texture_attribute(TowerAttributes::HP,    "../assets/textures/Attributes/Health.png");
    load_texture_attribute(TowerAttributes::MONEY, "../assets/textures/Attributes/Money.png");
    load_texture_attribute(TowerAttributes::RNG,   "../assets/textures/Attributes/Range.png");
    load_texture_attribute(TowerAttributes::DMG,   "../assets/textures/Attributes/Attack_Damage.png");
    load_texture_attribute(TowerAttributes::ROUND, "../assets/textures/Attributes/Round_Marker.png");

    // Font 
    load_font();
    fill_tower_attributes_map();
    fill_tower_names_map();
}


void ResourceHandler::fill_attribute_map(int type, std::array<int, 5> attributes){
    std::shared_ptr<std::map<int, int>> attr_map = std::make_shared<std::map<int, int>>();
    attr_map->emplace(TowerAttributes::HP, attributes.at(0));
    attr_map->emplace(TowerAttributes::DMG, attributes.at(1));
    attr_map->emplace(TowerAttributes::RNG, attributes.at(2));
    attr_map->emplace(TowerAttributes::ATKSPD, attributes.at(3));
    attr_map->emplace(TowerAttributes::MONEY, attributes.at(4));
    _tower_attributes[type] = attr_map;
}


void ResourceHandler::fill_tower_attributes_map(){
    
    // hp, dmg, rng, atk_spd, price


    fill_attribute_map(ObjectTypes::AoeTower, {30, 10, 100, 2, 100});
    fill_attribute_map(ObjectTypes::ArcherTower, {30, 10, 100, 3, 100});
    fill_attribute_map(ObjectTypes::SniperTower, {10, 30, 1000, 1, 150});
    fill_attribute_map(ObjectTypes::RepelMageTower, {30, 5, 120, 1, 180});


    // TODO: fill 
    // int health = 20, int damage = 15, int range = 100, int attack_speed = 3, int type = ObjectTypes::MudMageTower, int price = 140,
    fill_attribute_map(ObjectTypes::MudMageTower, {20,15,100,3,140});
    //  int health = 40, int damage = 40, int range = 80, int attack_speed = 2, int type = ObjectTypes::MudMageTower, int price = 250,
    fill_attribute_map(ObjectTypes::WaterMageTower, {40,40,80,2,250});

}

void ResourceHandler::fill_tower_names_map(){
    _tower_names.emplace(ObjectTypes::AoeTower, "Aoe") ;
    _tower_names.emplace(ObjectTypes::ArcherTower , "Archer");
    _tower_names.emplace(ObjectTypes::SniperTower , "Sniper");
    _tower_names.emplace(ObjectTypes::RepelMageTower , "Repel Mage");
    _tower_names.emplace(ObjectTypes::MudMageTower , "Mud Mage");
    _tower_names.emplace(ObjectTypes::WaterMageTower , "Water Mage");

}