#ifndef TOWER_DEFENCE_SRC_SIDEMENU
#define TOWER_DEFENCE_SRC_SIDEMENU

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "tower_drag_button.hpp"
#include "level.hpp"
#include "resource_handler.hpp"

#include "iostream"



/**
 * @brief Implements side menu of the game. 
 * Features: 
 * - 6 drag buttons to purchase towers
 * - one button to start rounds
 * - displays the rounds, cash and lives stats
 * @param game_resolution
 * @param sidebar_width
 * @param rh
 * @param level
 */
class SideMenu : public sf::Drawable {

public:

    SideMenu(float game_resolution, float sidebar_width, ResourceHandler& rh,   Level& level);
    ~SideMenu(){
        for (auto button : _drag_buttons){
            delete button;
        }
        delete _round_button;
        delete _round_button;
    }

    void update();
    void handle_events(sf::RenderWindow& window, const sf::Event& event);

    /**
     * @brief disables handle events
     * 
     */
    void disable_buttons();

    /**
     * @brief enables handle events
     * 
     */
    void enable_buttons();


    // check state for transition to round start.

    /**
     * @brief Get the the next game state, either continue in pause or
     * if round button pressed transition to round(implemented in game class)
     * 
     * @return int 
     */
    int get_state();
    
    /**
     * @brief Sets state to GameState::Pause 
     * 
     */
    void pause(); 

private:

    /**
     * @brief Set up the background image.
     * 
     */
    void setup_background();
    void setup_buttons();
    void setup_info_displays();
    void setup_info_display(int type, sf::Sprite& sprite, sf::Text& text_obj, sf::Vector2f pos, float char_size);

    void setup_menu_title();

    /**
     * @brief inherited from sf::Drawable, draws sidemenu as window.draw(SideMenu)
     * 
     * @param target 
     * @param states 
     */
    virtual void draw( sf::RenderTarget& target, sf::RenderStates states) const;

    /**
     * @brief disable buttons
     * 
     */
    bool _disable_buttons;

    /**
     * @brief gives the state that is in the next game cycle. either continue in pause or transition to round. 
     * 
     */
    int _state;

    /**
     * @brief Holds height of the menu.
     * 
     */
    float _game_resolution;

    /**
     * @brief  Holds width of the menu. 
     * 
     */
    float _side_menu_width;

    sf::Text _title; 
    sf::RectangleShape _background;

    sf::Sprite _cash_drawable;
    sf::Sprite _lives_drawable;
    sf::Sprite _round_count_drawable;


    sf::Text _round_count_text;

    /**
     * @brief displays the cash in text
     * 
     */
    sf::Text _cash_text;

    /**
     * @brief displays the lives in text
     * 
     */
    sf::Text _lives_text;

    sf::Color _fill_color;
    sf::Color _outline_color;

    std::vector< TowerDragButton *> _drag_buttons;

    // button to start round / maybe pause? 
    Button* _round_button; 

    // for drawing the dragging image on top of everything
    std::array< const sf::Sprite *, 6>  _drag_img_ptrs;

    // for drawing the dragging image on top of everything
    std::array< const sf::Sprite *, 6>  _drag_img_ptrs;

    // button to start round
    /**
     * @brief a pointer to the allocated round button
     * 
     */
    Button* _round_button; 


    /**
     * @brief holds pointers for each drag buttons dragging_image. 
     * Is either a pointer to the drag image sprite or a null pointer.
     * Only one element on the list is a pointer to a drag image if the drag flag is set, the others are null pointers.
     * Otherwise everything is a null pointer and nothing is drawn. 
     * The draw call draws the element that isn't a null pointer, so its on top of all other draw calls. 
     */
    std::array< const sf::Sprite *, 6>  _drag_img_ptrs;

    /**
     * @brief a reference to the games level class
     * 
     */
    Level& _level;

    /**
     * @brief a reference to the resource handler class, gives font, textures, and attributes to the drag buttons. 
     * 
     */
    ResourceHandler& _rh;
};


#endif