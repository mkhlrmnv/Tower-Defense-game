#ifndef TOWER_DEFENCE_SRC_SIDEMENU
#define TOWER_DEFENCE_SRC_SIDEMENU

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "tower_drag_button.hpp"
#include "level.hpp"
#include "resource_handler.hpp"

#include "iostream"

class SideMenu : public sf::Drawable {

public:

    SideMenu(float game_resolution, float sidebar_width, ResourceHandler& rh,   Level& level);
    ~SideMenu(){
        for (auto button : _drag_buttons){
            delete button;
        }
    }

    void update_displays();
    void handle_events(sf::RenderWindow& window, const sf::Event& event);

private:
    
    void setup_background();
    void setup_buttons();
    void setup_info_displays();
    void setup_menu_title();

    // derived from drawable;
    virtual void draw( sf::RenderTarget& target, sf::RenderStates states) const;

    //TODO: freeze buttons during gameplay?
    bool is_paused;

    float _game_resolution;
    float _side_menu_width;

    sf::Text _title; 
    sf::RectangleShape _background;

    sf::Text _round_count_text;
    sf::Text _cash_text;
    sf::Text _lives_text;

    sf::Color _fill_color;
    sf::Color _outline_color;

    std::vector< TowerDragButton *> _drag_buttons;

    // for drawing the dragging image on top of everything
    std::array< const sf::Sprite *, 6>  _drag_img_ptrs;

    Level& _level;

    // to get textures
    ResourceHandler _rh;
};


#endif