#include "game.hpp"
#include <thread>
#include <mutex>
std::mutex enemiesMutex;
std::mutex enemiesMutex_2;
std::mutex towersMutex;

// TODO: Delete spawning of towers after is handled by user
// TODO: Some kind of timer in between of round
// TODO: Smart enemies spawning mechanism in start round
// TODO: Maybe some slowing down of the game that it isn't so fucking fast

Game::Game(): 
    _game_resolution(800),
    _side_bar_width(300),
    _window(),
    _level(800, 20000, 50),
    _rh(),
    _renderer(),
    some_pos(200,200),
    _side_menu(float(_game_resolution), float(_side_bar_width), _rh, _level),
    _upgrade(800, _rh, _level, 50){
}

// Returns resolution of the game
int Game::get_game_resolution() const {
    return _game_resolution;
}

// Returns width of side menu
int Game::get_side_bar_width() const {
    return _side_bar_width;
}

// generated new level
int Game::generate_chosen_level_style(int chosen_lv){
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
        if(_level.read_file("../maps/example_map.txt")==-1){
            std::cout << "level file read failed" <<std::endl;
            return 0;
        }else{
            std::cout << "level file read successfull" <<std::endl;
        }
    }
    return 1;
}

// opens new window
void Game::open_window(){
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8; // You can adjust this value
    settings.depthBits = 24;
    settings.stencilBits = 8;
    
    _window.create(sf::VideoMode(_game_resolution + _side_bar_width, _game_resolution), "Tower Defence", sf::Style::Default, settings);
    _window.setPosition(sf::Vector2i(200, 0));
}

// runs whole game
void Game::run(){
    open_window();
    generate_chosen_level_style(LevelSelection::load); 

    /* 
    // TODO: Delete this after user can spawn own towers
    auto t1_pos = Vector2D(82*5, 1*80);
    auto t2_pos = Vector2D(82*5, 2*80);
    auto t3_pos = Vector2D(82*5, 3*80);
    auto t4_pos = Vector2D(82*3, 1*80);
    auto t5_pos = Vector2D(82*3, 2*80);
    auto t6_pos = Vector2D(82*3, 3*80);

    // Tower(level, health, damage, range, attack_speed, pos, type, price, level, single or not)
    _level.add_tower(new Basic_Tower(_level, t1_pos, 30, 10, 200, 1, 0, 100, 1, true));
    _level.add_tower(new Basic_Tower(_level, t2_pos, 30, 10, 200, 1, 1, 100, 1, true));
    _level.add_tower(new Basic_Tower(_level, t3_pos, 30, 10, 200, 1, 2, 100, 1, true));
    _level.add_tower(new Basic_Tower(_level, t4_pos, 30, 10, 200, 1, 3, 100, 1, true));
    _level.add_tower(new Basic_Tower(_level, t5_pos, 30, 10, 200, 1, 4, 100, 1, true));
    _level.add_tower(new Basic_Tower(_level, t6_pos, 30, 10, 200, 1, 5, 100, 1, true));
    */

    _renderer.make_drawable_level(_level);
    //_renderer.make_level_info_texts(_game_resolution, _side_bar_width);

    // manages tick rate of the game
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    // while window is open updates game
    while (_window.isOpen())
    {
        process_events();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > sf::seconds(1.f / 60.f)) // doesn't let game to update too fast
        {
            timeSinceLastUpdate -= sf::seconds(1.f / 60.f);
            process_events();
            //std::this_thread::sleep_for(std::chrono::milliseconds(10));
            update();
            //std::this_thread::sleep_for(std::chrono::milliseconds(10));
            render();
        }
    }
}

// updates whole game
// moves enemies, and calls attack function for all enemies and towers
void Game::update(){


     
    // uses two threads for this, one for updating enemies and one for towers
    std::thread enemiesThread(&Game::update_enemies, this);
    std::thread towersThread(&Game::update_towers, this);

    // if there are not enemies and round over variable hasn't been updates
    // new round starts

    // TODO::REMOVE FALSE!!!
    if (_level.get_enemies().empty() && !round_over && false) {
        _level.plus_round();
        round_over = true;
        start_round();
    }

    // waits that both threads are ready
    enemiesThread.join();
    towersThread.join();
    _side_menu.update();
    
}

void Game::process_events(){
    sf::Event event;
    while(_window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            _window.close();
            
        }
        _side_menu.handle_events(_window, event);
        _upgrade.handle_events(_window, event);
        // TODO: add events here, like button presses, dragging towers to map
    }
}

// renders current situation on map
void Game::render(){
    // because animation are at most five pictures
    // there is for loop until five
    for (int i = 0; i < 6; i++)
    {
        _window.clear();
        _renderer.draw_level(_window);
        _renderer.draw_enemies(_window, _level.get_enemies(), i);
        _renderer.draw_towers(_window, _level.get_towers(), i);
        _window.draw(_side_menu);
        _window.draw(_upgrade);

        _window.display(); // display the drawn entities

        // delay if needed to slow down game
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    // removes all towers and enemies with 0 hp, if their dying animation was already played
    for (auto* t : _level.get_towers()){
        if (t->get_health() <= 0 && t->get_state() == State::dying){
            _level.remove_tower(t);
        } 
    }
    for (auto* e : _level.get_enemies()){
        if (e->get_health() <= 0 && e->get_state() == State::dying){
            _level.remove_enemy(e);
        } 
    }
}

// starts new round
void Game::start_round(){
    round_over = false;
    for (int i = 0; i < (_difficulty_multiplier * _level.get_round()); i++)
    {
        Square* spawn_sq = _level.get_first_road();
        int rand_types = rand() % idk;
        int x = rand() % 80;
        int y = rand() % 40;
        Vector2D rand_pos = Vector2D(spawn_sq->get_center().x - (_level.get_square_size() / 2) + x, 1 + y);
        _level.add_enemy_by_type(rand_types, rand_pos);
    }
    if (idk < 7){
        idk++;
    }

    // waits 3sec to start new round
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}

// updates all enemies
void Game::update_enemies(){
    std::lock_guard<std::mutex> lock(enemiesMutex);
    for (Enemy* e : _level.get_enemies()){
        if (e->get_health() <= 0){ // if enemies hp is 0 sets state to dying
            e->set_state(State::dying);
        } else { // if not dead attacks OR moves
            if (!e->attack()){
                e->move();
            }
        }
    }
}

// updates all towers
void Game::update_towers(){
    std::lock_guard<std::mutex> lock(towersMutex);
    for (Tower* t : _level.get_towers()){
        if (t->get_health() <= 0){ // if hp is 0, sets state to dying
            t->set_state(State::dying);
        } else { // if not attacks
            t->attack();
        }
    }
}