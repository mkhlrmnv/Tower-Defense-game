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
        HP, DMG, RNG, ATKSPD, MONEY, UPGRADE
    };
};

class ResourceHandler{

public:
    ResourceHandler(){load_all_textures();}

    /**
     * @brief Get the texture of tower by ObjectType enum as reference. 
     * 
     * @param type 
     * @return sf::Texture& 
     */
    sf::Texture& get_texture_tower(int type);

    /**
     * @brief Get the texture of enemy by ObjectType enum as reference. 
     * 
     * @param type 
     * @return sf::Texture& 
     */
    sf::Texture& get_texture_enemy(int type);

    /**
     * @brief Get the texture of level square as reference.
     * 0 = grass, 
     * 1 = road, 
     * 2 = house
     * 
     * @param type 
     * @return sf::Texture& 
     */
    sf::Texture& get_texture_tile(int type);

    /**
     * @brief Get the texture of menus as reference.
     * 0 = start menu,
     * 1 = level menu,
     * 2 = side menu,
     * 3 = game over,
     * 4 = victory
     * 
     * @param type 
     * @return sf::Texture& 
     */
    sf::Texture& get_texture_menu(int type);

    /**
     * @brief Get the sf::Font object as reference.
     * 
     * @return sf::Font& 
     */
    sf::Font& get_font();

    /**
     * @brief Get the towers attribute with ObjectType and TowerAttribute.
     * 
     * @param tower_type 
     * @param attr_type 
     * @return int 
     */
    int  get_tower_info(int tower_type, int attr_type);

    /**
     * @brief Get the tower's name as const reference to a string.
     * 
     * @param type 
     * @return const std::string& 
     */
    const std::string& get_tower_name(int type);

    // function to access attribute textures
    // use heart, and money in as cash and lives
    /**
     * @brief Get the texture for attributes as a reference with TowerAttribute.
     * 
     * @param type 
     * @return sf::Texture& 
     */
    sf::Texture& get_texture_attribute(int type);
    
    // function to access tower attributes;
    const std::array<int, 5>& get_tower_info(int type);
    const std::string& get_tower_name(int type);
    
    // function to access tower attributes;
    int  get_tower_info(int tower_type, int attr_type);
    const std::string& get_tower_name(int type);

    // function to access attribute textures
    // use heart, and money in as cash and lives
    sf::Texture& get_texture_attribute(int type);
    
private:

    /**
     * @brief Calls all the load functions and etc. below, with correct textures and fonts.
     * 
     */
    void load_all_textures();

    // load functions for all textures
    // someimage.png -> sf::Texture
    void load_texture_tower(int type, const std::string& filename);

    
    /**
     * @brief Loads filename, creates a shared texture pointer and places it to the enemies map with key being the given type. 
     * 
     * @param type 
     * @param filename 
     */
    void load_texture_enemy(int type, const std::string& filename);

     /**
     * @brief Loads filename, creates a shared texture pointer and places it to the tiles map with key being the given type. 
     * 
     * @param type 
     * @param filename 
     */
    void load_texture_tile(int type, const std::string& filename);
    void load_font();

    void fill_attribute_map(int type, std::array<int, 5> attributes);
    void fill_tower_attributes_map();
    void fill_tower_names_map();

    void fill_tower_attributes();
    void fill_tower_names();

    /**
     * @brief Fills an attribute map pair with a the given attribute type as a key to a attribute value given in the list
     * 
     * @param type 
     * @param attributes 
     */
    void fill_attribute_map(int type, std::array<int, 5> attributes);

    /**
     * @brief Fills the 2D attribute map with all tower types
     * 
     */
    void fill_tower_attributes_map();

    /**
     * @brief fill tower names attribute map with all tower types 
     * 
     */
    void fill_tower_names_map();

    
    /**
     * @brief Map for holding tower texture shared pointers
     * 
     */
    std::map<int, std::shared_ptr<sf::Texture>> _towers_textures_ptr_map;

    /**
     * @brief Map for holding enemy texture shared pointers
     * 
     */
    std::map<int, std::shared_ptr<sf::Texture>> _enemies_textures_ptr_map;
    
    /**
     * @brief Map for holding level tile texture shared pointers
     * 
     */
    std::map<int, std::shared_ptr<sf::Texture>> _tiles_textures_ptr_map;

    // holds info for towers
    // Tower_type --> attribute list
    std::map<int, std::shared_ptr<std::map<int, int>>> _tower_attributes;
    std::map<int, const std::string> _tower_names;
    sf::Font _font;

    //menu graphics;
    std::map<int, std::shared_ptr<sf::Texture>> _attr_textures_ptr_map;

};


#endif