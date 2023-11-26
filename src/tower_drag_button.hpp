#ifndef TOWER_DEFENCE_SRC_TOWERDRAGBUTTON
#define TOWER_DEFENCE_SRC_TOWERDRAGBUTTON

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "button.hpp"
#include "resource_handler.hpp"

class TowerDragButton : public Button{
public:
TowerDragButton(int type, const std::string& name, sf::Vector2f position,  sf::Texture obj_texture, sf::Color outline, sf::Color fill, std::array<int, 5>& tower_attrs, const sf::Font* font, ResourceHandler& _rh);
    /* 
    1. set the position of the tower to where square where the mouse was released.
        1.1 if grid square empty call some function on level to create new tower. TODO: handle this including cash, purchases in side level
        1.2 otherwise dont make new object and release image
    reset drag_flag
    */ 
    
    void setup_button_texts();
    void setup_attribute_images();
    void set_attribute_image(int type, sf::Sprite& sprite, sf::Vector2f pos);
    

    void set_font();

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

    // get mouse coords and place dragging image on that position

    void set_dragging_drawable_offset(sf::RenderWindow& window); // TODO: remove
    void set_dragging_drawable_pos(sf::RenderWindow& window);

    // returns the dragging image for side menu, for drawing on top of all buttons. 
    const sf::Sprite* get_dragging_image() const ;
    int get_type() const;

    
    // call level create object, handle purchasing the tower
    virtual void some_action_from_level(sf::RenderWindow& window, Level& lv);

    // implements the operation of the drag trough events
    void handle_events(sf::RenderWindow& window, const sf::Event& event, Level& lv);    

protected:

    /* draw the dragging_image, static button image of object, bounding square, object name text,*/
    void draw(sf::RenderTarget& target, sf::RenderStates) const;


    // display object image in button. 
    sf::Texture _texture;

    // for drawing background for tower texture
    sf::RectangleShape _img_background;

    
    sf::Sprite _drawable_tower;

    // to show image behind mouse while dragging, use blurred image of the same image
    sf::Sprite _drawable_dragging_tower;


    // draw as emblems
    sf::Sprite _hp_img;
    sf::Sprite _dmg_img;
    sf::Sprite _rng_img;
    sf::Sprite _atkspd_img;

    sf::Text _price_text;

    sf::Text _hp_text;
    sf::Text _dmg_text;
    sf::Text _rng_text;
    sf::Text _atkspd_text;

    std::array<int, 5> _attributes;

    // offset for dragging image - reduce from mouse pos to set dragging_image pos
    sf::Vector2f _dragging_tower_offset;

    // where mouse was released -> determine grid from this
    sf::Vector2i _release_pos;

    // mirroring the images with scale, results in offset with the image position, this corrects the position for both dragging and static images
    // this should be same as the image size;
    float _flip_correction  = 80; 

    // determine image of the button, text, what will be created what will the button represent
    int _tower_type;
    int _tower_price;
    std::string _tower_name;

    // determines whether the image is dragged or not 
    bool _drag_flag;

    ResourceHandler _rh;

};




#endif