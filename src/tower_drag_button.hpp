#ifndef TOWER_DEFENCE_SRC_TOWERDRAGBUTTON
#define TOWER_DEFENCE_SRC_TOWERDRAGBUTTON

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "button.hpp"
#include "resource_handler.hpp"

/**
 * @brief A class to implement dragging towers to grid. 
 * @param type what object the button creates 
 * @param position location for the button
 * @param outline outline color of the button
 * @param fill fill color of the button
 * @param rh a reference to ResourceHandler class
 */

class TowerDragButton : public Button{
public:
TowerDragButton(int type, sf::Vector2f position,  sf::Color outline, sf::Color fill, ResourceHandler& rh);
   
    
    /**
     * @brief Set the drag flag to true.
     * 
     */
    void set_drag_flag();

    /**
     * @brief Set drag flag to false.
     * 
     */
    void reset_drag_flag();

    /**
     * @brief Get the drag flag object.
     * 
     * @return true 
     * @return false 
     */
    bool get_drag_flag() const ;

    /**
     * @brief Get the dragging image sf::Sprite. Used in SideMenu to draw the dragging image on top of everything.
     * 
     * @return const sf::Sprite* 
     */
    const sf::Sprite* get_dragging_image() const ;

    /**
     * @brief Get the ObjectType of the button.
     * 
     * @return int 
     */
    int get_type() const;

  

    /**
     * @brief Updates the buttons state. 
     * If cash is too low for purchase, sets the price text to red and disables the events. 
     * 
     * @param player_cash 
     */
    void update(int player_cash);


    /**
     * @brief Handles the button events.
     * If mouse is pressed on top of the button sets the drag flag on.
     * If mouse moves sets the new dragging image position. 
     * If mouse button is released, calls add_tower_to_release_square() and resets drag flag.
     * @param window 
     * @param event 
     * @param lv 
     */
    void handle_events(sf::RenderWindow& window, const sf::Event& event, Level& lv);    

protected:


    /**
     * @brief adds tower to the release square. Checks if the object is on the grid, if the square is grass, 
     * and handles the purchase with the level class if add_tower function succeeds.
     * 
     * @param window 
     * @param lv 
     */
    void add_tower_to_release_square(sf::RenderWindow& window, Level& lv);

    /**
     * @brief Set the dragging drawable position. 
     * Checks the mouse position and sets it to the member variable _release_pos.
     * 
     * @param window 
     */
    void set_dragging_drawable_pos(sf::RenderWindow& window);

    /**
     * @brief Sets up the tower image sprites to right locations, sizes, etc.
     * Called in constructor.
     * 
     */
    void setup_tower_images();

    /**
     * @brief Sets up the button sf::Texts objects to right locations etc. 
     * 
     */
    void setup_button_texts();

    /**
     * @brief Sets up the attribute images to close to the texts.
     * 
     */
    void setup_attribute_images();

    /**
     * @brief a helper function for the function above 
     * Sets up a sprite according to given position and ObjectType.  
     * 
     * @param type 
     * @param sprite 
     * @param pos 
     */
    void setup_attribute_image(int type, sf::Sprite& sprite, sf::Vector2f pos);
    
    /**
     * @brief Sets up the font to all texts.
     * 
     */
    void setup_font();


    /**
     * @brief Inherited from the sf::Drawable class, so that the button can be drawn as window.draw(Button).
     * Draws the static tower image of object, bounding square, object attribute texts.
     * 
     * @param target 
     * @param states 
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /**
     * @brief a background for tower texture
     * 
     */
    sf::RectangleShape _img_background;

    /**
     * @brief a sprite for the static tower image
     * 
     */
    sf::Sprite _drawable_tower;
    
    /**
     * @brief a sprite for the tower image following the mouse when dragging
     * 
     */
    sf::Sprite _drawable_dragging_tower;

    /**
     * @brief a sprite for the static tower image
     * 
     */
    sf::Sprite _hp_img;

    /**
     * @brief a sprite for displaying damage image
     * 
     */
    sf::Sprite _dmg_img;

    /**
     * @brief a sprite for displaying the range image
     * 
     */
    sf::Sprite _rng_img;

    /**
     * @brief a sprite for displaying the attack speed image
     * 
     */
    sf::Sprite _atkspd_img;

    /**
     * @brief a text object for displaying the towers price
     * 
     */
    sf::Text _price_text;

    /**
     * @brief a text object for displaying the hp of the tower
     * 
     */
    sf::Text _hp_text;
    
    /**
     * @brief a text object for displaying the damage of the tower
     * 
     */
    sf::Text _dmg_text;
    
    /**
     * @brief a text object for displaying the range of the tower
     * 
     */
    sf::Text _rng_text;
    
    /**
     * @brief a text object for displaying the attack speed of the tower
     * 
     */
    sf::Text _atkspd_text;


    /**
     * @brief the position where the mouse was released when drag flag is set
     * 
     */    
    sf::Vector2i _release_pos;

    /**
     * @brief size of the tower images.
     * 
     */
    float _img_size  = 60; 
    /**
     * @brief size of the attribute images (hp, dmg, etc.)
     * 
     */
    float _attr_img_size = 12;

    /**
     * @brief tower's ObjectType
     * 
     */
    int _tower_type;

    /**
     * @brief tower's price, displayed in _price_text
     * 
     */
    int _tower_price;

    /**
     * @brief Determines if the button is usable.
     * 
     */
    bool _button_enabled;

    /**
     * @brief Determines if the image is dragged or not.
     * 
     */
    bool _drag_flag;

    /**
     * @brief Handles Tower textures, font, name, attribute values and images from given tower type.
     * 
     */
    ResourceHandler& _rh;

};




#endif