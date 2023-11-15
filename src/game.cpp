#include "game.hpp"


Game::Game(): _game_resolution(800), _side_bar_width(300), _window(), _level(800, 250, 50), _renderer(), some_pos(200,200){
}

int Game::get_game_resolution() const {
    return _game_resolution;
}

int Game::get_side_bar_width() const {
    return _side_bar_width;
}

int Game::generate_chosen_level_style(int chosen_lv){
    // TODO: maybe do this on level class?
    // TODO: add choosing feature, in a game start menu
     _level.make_grid();
    if(chosen_lv == LevelSelection::random){
        if(!_level.randomly_generate()){
            std::cout << "random level generation failed" <<std::endl;
            return 0;
        }else{
            std::cout << "random level generation successful" <<std::endl;
        }
    }else if(chosen_lv == LevelSelection::load){
        if(_level.read_file("/Users/mkhlrmnv/Desktop/cpp_project/tower-defence/maps/example_map.txt")==-1){
            std::cout << "level file read failed" <<std::endl;
            return 0;
        }else{
            std::cout << "level file read successfull" <<std::endl;
        }
    }
    return 1;
}

void Game::open_window(){
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; // You can adjust this value
    settings.depthBits = 24;
    settings.stencilBits = 8;
    
    _window.create(sf::VideoMode(_game_resolution + _side_bar_width, _game_resolution), "Tower Defence", sf::Style::Default, settings);
    _window.setPosition(sf::Vector2i(200, 0));
}


void Game::run(){

    open_window();

    // int choice = rand() % 2; // chose randomly to load level or to randomly generate

    generate_chosen_level_style(LevelSelection::load); 

    // test drawing objects

    /*for (int i = 0; i < 5; i++){
        auto pos = Vector2D(rand() % 800, rand() % 800);
        _level.add_enemy(new Enemy(_level, 1, 1, 1, 1, pos, 1, 1, 1));
    }

    for (int j = 0; j < 5; j++){
        auto pos2 = Vector2D(rand() % 800, rand() % 800);
        _level.add_tower(new Tower(_level, 1, 1, 1, 1, pos2, 1, 1, 1));
    }*/
    
    auto e1_pos = Vector2D(85*4, 1*80);
    auto e2_pos = Vector2D(85*4, 2*80);

    auto t1_pos = Vector2D(82*5, 2*80);
    auto t2_pos = Vector2D(82*6, 2*80);
    
    _level.add_enemy(new Enemy(_level, 1, 1, 1, 1, e1_pos, 1, 1, 1));
    // _level.add_enemy(new Enemy(_level, 1, 1, 1, 1, e2_pos, 1, 1, 1));

    _level.add_tower(new Tower(_level, 1, 1, 1, 1, t1_pos, 1, 1, 1));
    _level.add_tower(new Tower(_level, 1, 1, 1, 1, t2_pos, 1, 1, 1));

    // std::cout << res << res2 << res3 << res4 << std::endl;
    
    //***************

    _renderer.make_drawable_level(_level);
    _renderer.make_drawable_object_textures();
    _renderer.make_level_info_texts(_game_resolution, _side_bar_width);

    while(_window.isOpen()){
        process_events();
        update();
        render();
    }
}

void Game::update(){
    // update game state: buys, attacks, movements,  etc here
    for (Enemy* e : _level.get_enemies()){
        e->move();
    }
}

void Game::process_events(){

    sf::Event event;

    while(_window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            _window.close();
        }
        // TODO: add events here, like button presses, dragging towers to map
    }
}

void Game::render(){

    _window.clear(); // clear all drawn entities

    // draw entities, every function calls _window.draw([DRAWABLE OBJECT])
    _renderer.draw_level(_window);
    _renderer.draw_enemies(_window, _level.get_enemies());
    _renderer.draw_towers(_window, _level.get_towers());
    _renderer.draw_cash(_window, _level.get_cash());
    _renderer.draw_lives(_window, _level.get_lives());
    _renderer.draw_round_count(_window, _level.get_round());

    _window.display(); // display the drawn entities

}