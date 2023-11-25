#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <button.hpp>
#include <tower_drag_button.hpp>
#include <side_menu.hpp>
#include <level.hpp>
#include <iostream>
#include <resource_handler.hpp>
#include <upgrade.hpp>
#include <main_menu.hpp>
#include <choose_level_menu.hpp>
#include <renderer.hpp>




int test_button(){



    sf::Font font;
    if(!font.loadFromFile("/home/klind/tower_defence/assets/fonts/Ubuntu-R.ttf")){std::cout << "succesfull font load" << std::endl;};
    sf::RenderWindow window(sf::VideoMode(1100, 800), "My window");
    ResourceHandler rh;
    font = rh.get_font();
    Level lv(20,20,20); // just to run test 

    Button btn("iaoai", {100, 100}, {100, 100}, sf::Color::Black, sf::Color::White);
    btn.set_font(font);
    btn.set_position_text_down({100, 100});

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            
            btn.handle_events(window, event, lv);

        }
        

        window.clear();
        window.draw(btn);
        window.display();

    }

    return 0;
}

int test_drag_button(){
    
    sf::RenderWindow window(sf::VideoMode(1100, 800), "My window");
    
    ResourceHandler rh;
    ResourceHandler rh;
    Level lv(20,20,20); // just to run test 

    auto tower_name = rh.get_tower_name(ObjectTypes::AoeTower);
    auto tower_texture = rh.get_texture_tower(ObjectTypes::AoeTower);
    auto attrs = rh.get_tower_info(ObjectTypes::AoeTower);

    TowerDragButton dt_btn(ObjectTypes::AoeTower, tower_name, {100,100}, tower_texture, sf::Color::White, sf::Color::Black, attrs);
    dt_btn.set_font(rh.get_font());

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window.close();
            }
           dt_btn.handle_events(window, event, lv);
        }
        

        window.clear();
        window.draw(dt_btn);
        window.display();

    }

    return 0;
}

int test_menu(){

    std::cout << "i am calleed" <<std::endl; 
    
    sf::RenderWindow window(sf::VideoMode(1100, 800), "My window");
    window.setPosition({100, 0});
    
    Level lv(800, 2000, 10); // just to run test 

    ResourceHandler rh;


    SideMenu sm(800, 300, rh,  lv);


    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window.close();
            }
            sm.handle_events(window, event);

            if(event.type == sf::Event::MouseButtonPressed){
                auto pos = sf::Mouse::getPosition(window);
                std::cout << "x" << pos.x << std::endl;
                std::cout << "y" << pos.y << std::endl;
            }
        
        }


        
        sm.update();

        window.clear();
        window.draw(sm);
        window.display();

    }

    return 0;
}

int test_coordinate_and_indexes(){
    sf::RenderWindow window(sf::VideoMode(1100, 800), "My window");
    Level lv(800,20,20); // just to run test
    Button btn("iaoai", {100, 100}, {100, 100}, sf::Color::Black, sf::Color::White);
    ResourceHandler rh;


    
    auto func1_return1 = btn.window_coords_to_grid_index(sf::Vector2i(80*4 + 20, 80*2 + 45), lv);
    auto func2_return1 = btn.window_coords_to_level_coords(sf::Vector2i(80*4 + 20, 80*2 + 45));
    

    std::pair<int, int> func1_comp_val1 = std::make_pair(4,2);
    Vector2D func2_comp_val1(80*2 + 45, 80*4 + 20);

    if(!(func1_return1 == func1_comp_val1)){
        
        std::cout << "window coords to index failed" << std::endl;
        std::cout << "expected: " << func1_comp_val1.first <<" " << func1_comp_val1.second << std::endl;
        std::cout << "got: " << func1_return1.first <<" " << func1_return1.second << std::endl;

        return -1;
        
    }else if(!(func2_return1 == func2_comp_val1)){

        std::cout << "window coords to level coords failed" << std::endl;
         std::cout << "expected: " << func2_comp_val1.x <<" " << func2_comp_val1.y << std::endl;
        std::cout << "got: " << func2_return1.x <<" " << func2_return1.y << std::endl;
        return -1;
    }else{

        std::cout << "tests ok" << std::endl;
    }

    window.close();
    return 1;

}

int main(){
    test_menu();
}