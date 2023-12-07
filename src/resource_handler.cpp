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

sf::Texture& ResourceHandler::get_texture_menu(int type){
    return *(_menu_textures_ptr_map[type]);
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

void ResourceHandler::load_texture_menu(int type, const std::string& filename){
    std::shared_ptr<sf::Texture> tx = std::make_shared<sf::Texture>();
    tx->loadFromFile(filename);
    _menu_textures_ptr_map[type] = tx;
}

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
    load_texture_tile(0, "../assets/textures/VerySmallSize_32x32/VerySmall_Tiles_32x32/VerySmall_GrassTile_32x32.png");
    load_texture_tile(1, "../assets/textures/VerySmallSize_32x32/VerySmall_Tiles_32x32/VerySmall_RoadTile_32x32.png");
    load_texture_tile(2, "../assets/textures/VerySmallSize_32x32/VerySmall_Tiles_32x32/House_32x32.png");

    //Attributes 
    load_texture_attribute(TowerAttributes::ATKSPD, "../assets/textures/Attributes/16x16/Attack_Speed.png");
    load_texture_attribute(TowerAttributes::HP,    "../assets/textures/Attributes/16x16/Hitpoints.png");
    load_texture_attribute(TowerAttributes::MONEY, "../assets/textures/Attributes/16x16/Money.png");
    load_texture_attribute(TowerAttributes::RNG,   "../assets/textures/Attributes/16x16/Attack_Range.png");
    load_texture_attribute(TowerAttributes::DMG,   "../assets/textures/Attributes/16x16/Attack_Damage.png");
    load_texture_attribute(TowerAttributes::ROUND, "../assets/textures/Attributes/16x16/Round_Marker_New.png");

    //Menus
    load_texture_menu(0, "../assets/textures/Menu/Start_Menu_1.png");
    load_texture_menu(1, "../assets/textures/Menu/Start_Menu_2.png");
    load_texture_menu(2, "../assets/textures/Menu/GUI_New.png");
    load_texture_menu(3, "../assets/textures/Menu/Game_Over_Screen.png");
    load_texture_menu(4, "../assets/textures/Menu/You_Won_Screen.png");
    

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


    fill_attribute_map(ObjectTypes::AoeTower, {400, 50, 200, 40, 150});
    fill_attribute_map(ObjectTypes::ArcherTower, {300, 25, 250, 20, 100});
    fill_attribute_map(ObjectTypes::SniperTower, {200, 100, 999, 120, 200});
    fill_attribute_map(ObjectTypes::RepelMageTower, {350, 0, 150, 50, 250});


    // TODO: fill 
    // int health = 20, int damage = 15, int range = 100, int attack_speed = 3, int type = ObjectTypes::MudMageTower, int price = 140,
    fill_attribute_map(ObjectTypes::MudMageTower, {400, 30, 180, 30, 200});
    //  int health = 40, int damage = 40, int range = 80, int attack_speed = 2, int type = ObjectTypes::MudMageTower, int price = 250,
    fill_attribute_map(ObjectTypes::WaterMageTower, {300, 40, 150, 25, 250});

}

void ResourceHandler::fill_tower_names_map(){
    _tower_names.emplace(ObjectTypes::AoeTower, "Aoe") ;
    _tower_names.emplace(ObjectTypes::ArcherTower , "Archer");
    _tower_names.emplace(ObjectTypes::SniperTower , "Sniper");
    _tower_names.emplace(ObjectTypes::RepelMageTower , "Repel Mage");
    _tower_names.emplace(ObjectTypes::MudMageTower , "Mud Mage");
    _tower_names.emplace(ObjectTypes::WaterMageTower , "Water Mage");

}