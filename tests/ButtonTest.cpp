#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <button.hpp>
#include <tower_drag_button.hpp>
#include <level.hpp>
#include <iostream>



int test_button(){
    
    sf::Font font;
    if(!font.loadFromFile("/home/klind/tower_defence/assets/fonts/Ubuntu-R.ttf")){std::cout << "succesfull font load" << std::endl;};
    sf::RenderWindow window(sf::VideoMode(1100, 800), "My window");
    
    Level lv(20,20,20); // just to run test 

    Button btn("iaoai", {100, 100}, {100, 100}, sf::Color::Black);
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
    
    sf::Font font;
    if(!font.loadFromFile("/home/klind/tower_defence/assets/fonts/Ubuntu-R.ttf")){std::cout << "succesfull font load" << std::endl;};
    sf::RenderWindow window(sf::VideoMode(1100, 800), "My window");
    
    Level lv(20,20,20); // just to run test 

    sf::Texture tower_texture; 
    tower_texture.loadFromFile("/home/klind/tower_defence/assets/textures/ArcherTower/ArcherTower_Right.png");

    TowerDragButton dt_btn("$200    ", {80,80}, {100,100}, sf::Color::Black, tower_texture, 1);
    dt_btn.set_font(font);

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

int main(){
    return test_drag_button();
}