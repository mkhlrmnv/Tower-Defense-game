#ifndef TOWER_DEFENCE_SRC_SIDEMENU
#define TOWER_DEFENCE_SRC_SIDEMENU

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "tower_drag_button.hpp"
#include "level.hpp"
#include "resource_handler.hpp"

#include "iostream"


// TODO: Implement start round button!
// TODO: Tweak the attributes in RH according to final object attributes
//TODO: change bakground and tweak buttons accordingly

class SideMenu : public sf::Drawable {

public:

    SideMenu(float game_resolution, float sidebar_width, ResourceHandler& rh,   Level& level);
    ~SideMenu(){
        for (auto button : _drag_buttons){
            delete button;
        }
        delete _round_button;
    }

    void update();
    void handle_events(sf::RenderWindow& window, const sf::Event& event);
    void disable_buttons();
    void enable_buttons();

    // check state for transition to round start.
    int get_state();
    
    // sets state to GameState::Pause 
    void pause(); 

private:
    
    void setup_background();
    void setup_drag_buttons();
    void setup_round_button();
    void setup_info_displays();
    void setup_info_display(int type, sf::Sprite& sprite, sf::Text& text_obj, sf::Vector2f pos, float char_size);

    // derived from drawable;
    virtual void draw( sf::RenderTarget& target, sf::RenderStates states) const;

    //TODO: freeze buttons during gameplay?
    bool _disable_buttons;

    int _state;

    float _game_resolution;
    float _side_menu_width;

    sf::Sprite _background_img;

    sf::Sprite _cash_drawable;
    sf::Sprite _lives_drawable;
    sf::Sprite _round_count_drawable;


    sf::Text _round_count_text;
    sf::Text _cash_text;
    sf::Text _lives_text;

    sf::Color _fill_color;
    sf::Color _outline_color;

    std::vector< TowerDragButton *> _drag_buttons;

    // button to start round / maybe pause? 
    Button* _round_button; 

    // for drawing the dragging image on top of everything
    std::array< const sf::Sprite *, 6>  _drag_img_ptrs;

    Level& _level;

    // to get textures
    ResourceHandler& _rh;
};


#endif