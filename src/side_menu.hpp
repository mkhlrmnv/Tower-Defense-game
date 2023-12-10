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
    SideMenu(const SideMenu&) = delete; 
    SideMenu& operator=(const SideMenu&) = delete;

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
    
   

    /**
     * @brief Get the the next game state, either continue in pause or
     * if round button pressed transition to round(implemented in game class)
     * 
     * @return int 
     */
    int get_state();
    
    /**
     * @brief Sets state back to GameState::Pause 
     * 
     */
    void reset(); 

     /**
     * @brief updates the texts and buttons according to the cash, lives, rounds of level
     * 
     */
    void update();

    /**
     * @brief distributes the window and event references to the buttons.
     * 
     * @param window 
     * @param event 
     */
    void handle_events(sf::RenderWindow& window, const sf::Event& event);

   
   

private:

    /**
     * @brief Set up the background image.
     * 
     */
    void setup_background();

    /**
     * @brief make new drag buttons and put them on the list. 
     * 
     */
    void setup_drag_buttons();
    /**
     * @brief make new button
     * 
     */
    void setup_round_button();

    /**
     * @brief Setup the info displays
     * 
     */
    void setup_info_displays();

    /**
     * @brief Set the up info display, called in the function above.
     * 
     * @param type 
     * @param sprite 
     * @param text_obj 
     * @param pos 
     * @param char_size 
     */
    void setup_info_display(int type, sf::Sprite& sprite, sf::Text& text_obj, sf::Vector2f pos, float char_size);

    // derived from drawable;
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

    /**
     * @brief a sprite for the background image of the menu
     * 
     */
    sf::Sprite _background_img;

    /**
     * @brief a sprite for the cash icon
     * 
     */
    sf::Sprite _cash_drawable;

    /**
     * @brief a sprite for the health icon
     * 
     */
    sf::Sprite _lives_drawable;

    /**
     * @brief a sprite for the round icon
     * 
     */
    sf::Sprite _round_count_drawable;

    /**
     * @brief displays the round count as text
     * 
     */
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

    /**
     * @brief given as fill color to the drag buttons
     * 
     */
    sf::Color _fill_color;

    /**
     * @brief given as outline color to the drag buttons
     * 
     */
    sf::Color _outline_color;

    /**
     * @brief holds pointers to the allocated drag buttons. 
     * 
     */
    std::vector< TowerDragButton *> _drag_buttons;

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