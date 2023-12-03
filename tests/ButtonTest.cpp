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
    Button btn("iaoai", {100, 100}, {100, 100}, sf::Color::Black, sf::Color::White, rh.get_font());
    //btn.set_font(font);

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
    TowerDragButton dt_btn(ObjectTypes::AoeTower, {100,100}, sf::Color::White, sf::Color::Black,  rh);

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
    ResourceHandler rh;
    Button btn("iaoai", {100, 100}, {100, 100}, sf::Color::Black, sf::Color::White, rh.get_font());
    
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

int test_rh(){

    ResourceHandler rh;

    for(int i=0; i<6; i++){
        for(int j=0; j<5; j++){
            
            std::cout << rh.get_tower_info(i, j) << std::endl;

        }
    }



    return 1;
}

int test_text(){

    
    sf::RenderWindow window(sf::VideoMode(1100, 800), "My window");
    window.setPosition({100, 0});
    
    /*
    
    sf::Font font;
    if(!font.loadFromFile("/home/klind/tower_defence/assets/fonts/Ubuntu-R.ttf")){
        std::cout << "font load failed" << std::endl;
    }
    */

    ResourceHandler rh;
   
    sf::Text text("test text", rh.get_font());
    text.setCharacterSize(30);
    text.setPosition(100.f, 100.f);
    text.setFillColor(sf::Color::White);

    std::cout << "text.getGlobalBounds().height " << text.getGlobalBounds().height << std::endl;
    std::cout << "text.getGlobalBounds().width " << text.getGlobalBounds().width << std::endl;
    std::cout << "text.getGlobalBounds().left " << text.getGlobalBounds().left << std::endl;
    std::cout << "text.getGlobalBounds().top " << text.getGlobalBounds().top << std::endl;

    std::cout << "text.getLocalBounds().height " << text.getLocalBounds().height << std::endl;
    std::cout << "text.getLocalBounds().width " << text.getLocalBounds().width << std::endl;
    std::cout << "text.getLocalBounds().left " << text.getLocalBounds().left << std::endl;
    std::cout << "text.getLocalBounds().top " << text.getLocalBounds().top << std::endl;

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
        }

        
        window.clear();
        window.draw(text);
        window.display();

    }

    return 1;
}

int test_rh2(){

    
    sf::RenderWindow window(sf::VideoMode(1100, 800), "My window");
    window.setPosition({100, 0});
    
    ResourceHandler rh;
    
    sf::Sprite spr;
    spr.setPosition(0,0);
    spr.setTexture(rh.get_texture_menu(4));


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
        }

        
        window.clear();
        window.draw(spr);
        window.display();

    }

    return 1;
}

int test_upgrade(){

    sf::RenderWindow window(sf::VideoMode(1100, 800), "My window");
    window.setPosition({100, 0});
    
    ResourceHandler rh;
    Level level(800,200,200);
    Upgrade u(800, rh, level, 2);

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
            u.handle_events(window, event);
        }

        
        window.clear();
        window.draw(u);
        window.display();

    }

    return 1;

}

int test_main_menu(){

    sf::RenderWindow window(sf::VideoMode(1100, 800), "My window");
    window.setPosition({100, 0});
    
    ResourceHandler rh;
    Level level(800,200,200);
    MainMenu mm( rh, level);
    ChooseLevelMenu clm( rh, level);

    int game_state = 0;
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

            switch (game_state)
            {
            case 0:
                mm.handle_events(window, event);
                game_state = mm.get_state();
                if(game_state != 0){
                    mm.disable_menu();
                }
                break;
            
            case 1:
                clm.handle_events(window, event);
                game_state = clm.get_state();
                if(game_state != 1){
                    clm.disable_menu();
                }
                break;

            default:
                std::cout << clm.get_level_to_load() << std::endl;
                window.close();
                break;
            }

        }
        window.clear();
        switch (game_state)
                {
                case 0:
                    window.draw(mm);
                    break;
                
                case 1:
                    window.draw(clm);
                    break;
                
             
                }
        window.display();

    }

    return 1;
}

int test_choose_level_menu(){

    sf::RenderWindow window(sf::VideoMode(1100, 800), "My window");
    window.setPosition({100, 0});
    
    ResourceHandler rh;
    Level level(800,200,200);
    ChooseLevelMenu clm(rh, level);

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

            clm.handle_events(window, event);

        }
        
        window.clear();
        window.draw(clm);
        window.display();

    }

    return 1;
}

int test_end_screen(){

    sf::RenderWindow window(sf::VideoMode(1100, 800), "My window");
    window.setPosition({100, 0});
    
    ResourceHandler rh;
    Level level(800,200,200);
    Renderer renderer(rh);

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
        }
        
        window.clear();
        renderer.draw_end_screen_lose(window);
        window.display();

    }

    return 1;
}

int main(){
    //test_button();
    //test_drag_button();
    //test_rh();
    //test_rh2();
    test_menu(); 
    //test_upgrade();
    //test_main_menu();
    //test_choose_level_menu();
    //test_end_screen();
};   