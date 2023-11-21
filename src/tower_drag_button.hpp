#ifndef TOWER_DEFENCE_SRC_TOWERDRAGBUTTON
#define TOWER_DEFENCE_SRC_TOWERDRAGBUTTON

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "button.hpp"

class TowerDragButton : public Button{
public:
    TowerDragButton(){}
    TowerDragButton(const std::string& price, sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Texture obj_texture, int tower_type);

    /* 
    1. set the position of the tower to where square where the mouse was released.
        1.1 if grid square empty call some function on level to create new tower. TODO: handle this including cash, purchases in side level
        1.2 otherwise dont make new object and release image
    reset drag_flag
    */ 
    
    
    void set_drag_flag();
    void reset_drag_flag();
    bool get_drag_flag() const ;

    // get mouse coords and place dragging image on that position

    void set_dragging_drawable_offset(sf::RenderWindow& window);

    void set_dragging_drawable_pos(sf::RenderWindow& window);
    
    // define to create object to place in mouse release pos
    virtual void some_action_from_level(Level &lv){} 

    // implements the operation of the drag trough events
    void handle_events(sf::RenderWindow& window, const sf::Event& event, Level& lv);    

protected:

    /* draw the dragging_image, static button image of object, bounding square, object name text,*/
    virtual void draw(sf::RenderTarget& target, sf::RenderStates) const;




// display object image in button. 
sf::Texture _texture;
sf::Sprite _drawable_tower;

// scale image accordingly
float _scale = 0.05;

// to show image behind mouse while dragging, use blurred image of the same image
sf::Sprite _drawable_dragging_tower;

// offset for dragging image - reduce from mouse pos to set dragging_image pos
sf::Vector2f _dragging_tower_offset;
// where mouse was released -> determine grid from this
sf::Vector2f _release_pos;
// determine image of the button, text, what will be created what will the button represent
int _tower_type;
// determines whether the image is dragged or not 
bool _drag_flag;

};




#endif