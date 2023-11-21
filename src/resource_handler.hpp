#ifndef TOWER_DEFENCE_SRC_RESOURCE_HANDLER
#define TOWER_DEFENCE_SRC_RESOURCE_HANDLER

#include<SFML/Graphics.hpp>
#include<memory>

/* 
    loads ALL textures and gives them as pointers.
    needs to be created in game class, pass as reference
*/

// 1. TODO: How to manage state
// 2. TODO: Automate loading somehow
// 3. TODO: Load rest of textures.


namespace ObjectTextureTypes
{ 
    enum{
        AoeTower,
        ArcherTower,
        BossKnight,
        FastBoy,
        FogMage,
        HealerPriest,
        MudMageTower,
        InfernoMage,
        NoobSkeleton_NoAttack,
        NoobDemon_CanAttack,
        RepelMageTower,
        SniperTower,
        TankOrc,
        WaterMageTower,
    };
}


class ResourceHandler{

public:
    
    ResourceHandler(){load_all_textures(); load_font();}
    sf::Texture& get_texture(int object_type, int object_state);
    sf::Font& get_font();
    
private:

    void load_all_textures();

    // someimage.png -> sf::Texture
    void load_texture(int object_type, int object_state, const std::string& filename);

    void load_font();

    sf::Font _font;

    // object_type, state, -->  texture_ptr
    std::map<std::pair<int, int>, std::shared_ptr<sf::Texture>> _texture_ptr_map;

    //
};


#endif