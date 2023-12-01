#ifndef TOWER_DEFENCE_SRC_TOWERDRAGBUTTON
#define TOWER_DEFENCE_SRC_TOWERDRAGBUTTON

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "button.hpp"
#include "resource_handler.hpp"

class TowerDragButton : public Button{
public:
TowerDragButton(int type, sf::Vector2f position,  sf::Color outline, sf::Color fill, ResourceHandler& rh);
    /* 
    1. set the position of the tower to where square where the mouse was released.
        1.1 if grid square empty call some function on level to create new tower. 
        1.2 otherwise dont make new object and release image
    reset drag_flag
    */ 
    

    void set_drag_flag();
    void reset_drag_flag();
    bool get_drag_flag() const ;

    // returns the dragging image for SideMenu class for drawing on top of all buttons. 
    const sf::Sprite* get_dragging_image() const ;
    int get_type() const;


    // implements the operation of the drag trough events
    void handle_events(sf::RenderWindow& window, const sf::Event& event, Level& lv);    

protected:

       // call level create object, handle purchasing the tower
    void add_tower_to_release_square(sf::RenderWindow& window, Level& lv);

    // get mouse coords and place dragging image on that position
    void set_dragging_drawable_pos(sf::RenderWindow& window);
    void setup_tower_images();
    void setup_button_texts();
    void setup_attribute_images();
    void setup_attribute_image(int type, sf::Sprite& sprite, sf::Vector2f pos);
    

    void setup_font();

    /* draw the dragging_image, static button image of object, bounding square, object name text,*/
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    // for drawing background for tower texture
    sf::RectangleShape _img_background;

    // on button
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

    // where mouse was released -> determine grid from this
    sf::Vector2i _release_pos;

    // mirroring the images with scale, results in offset with the image position, this corrects the position for both dragging and static images
    // this should be same as the image size;
    float _flip_correction  = 80; 

    // determine image of the button, text, what will be created what will the button represent
    int _tower_type;
    int _tower_price;

    // determines whether the image is dragged or not 
    bool _drag_flag;


    // handles Tower textures, font, name, attribute values and images from given tower type
    ResourceHandler& _rh;

};




#endif