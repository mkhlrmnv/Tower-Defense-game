#include "game.hpp"
#include <thread>
#include <mutex>

// TODO: Some kind of timer in between of round

//TODO: are objects destoryed properly if transititon to end mid round?

//TODO: balance game and update tower attribute values in resource handle for tower drag buttons!

//TODO: remove redundant parts?

Game::Game(): 
    _game_resolution(800),
    _side_bar_width(300),
    _window(),
    _level(_game_resolution, 500, 30),
    _rh(),
    _renderer(_rh),
    _main_menu(_rh, _level),
    _level_menu(_rh, _level),
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
    // TODO: REDUNDANT REMOVE 
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
    _window.setVerticalSyncEnabled(true);
}

// runs whole game
void Game::run(){
    open_window();
    //generate_chosen_level_style(LevelSelection::load); 

    //_renderer.make_drawable_level(_level);
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
            timeSinceLastUpdate -= sf::seconds(1.f / 60.f); // 60f can be changed to 30f if tick rate 30 is wanted
            process_events();
            update();
            render();
        }

    }
}

// updates whole game
// moves enemies, and calls attack function for all enemies and towers
void Game::update(){


    switch (_game_state)
    {
    case GameState::Pause:

        update_towers();
        _side_menu.update();

        // transition to victory
        if(_rounds_to_survive < _level.get_round()){
            _game_state = GameState::Victory;
            _side_menu.pause();
        }
    
    break;
    
    case GameState::Round:

        _side_menu.update();
        update_enemies();
        update_towers();

        // transition to paused after all enemies are dead
        if (_level.get_enemies().empty() && !_round_over && _level.get_lives() > 0) {
            _level.plus_round();
            _round_over = true;
            _game_state = GameState::Pause;
            _side_menu.pause();
        }

        // transition to game over when no lives left
        if (_level.get_lives() < 1){
            _round_over = true;
            _game_state = GameState::GameOver;
            _side_menu.pause();
        }
    
    break;

    }

    // OG HERE 
    /*
    if(_game_state == GameState::Pause || _game_state == GameState::Round){
        update_enemies();
        update_towers();

        // if there are not any enemies starts new round
        // TODO: Remove this when there are "start round" button
        if (_level.get_enemies().empty() && !_round_over && _level.get_lives() > 0) {
            _level.plus_round();
            _round_over = true;
        }
        _side_menu.update();
    } */

}

// Process events in loop:  clicks, button presses
void Game::process_events(){
    sf::Event event;
    while(_window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            _window.close();
            
        }

        // events based on _game_state
        switch (_game_state)
        {
        case GameState::StartMenu:
            _main_menu.handle_events(_window, event);
            _game_state = _main_menu.get_state();

            // check game state transition
            if(_game_state == GameState::Pause){


                std::cout << " from StartMenu going to: "<<_game_state << std::endl;

                _level.make_grid();
                _level.randomly_generate();
                //std::cout << "MAP RANDOM GENERATION HAPPENS" << std::endl;
                _renderer.make_drawable_level(_level);
                _main_menu.disable_menu(); // redundant
               // std::cout << "DRAWING LEVEL  HAPPENS" << std::endl;


            }else if(_game_state == GameState::MapMenu){
                
                std::cout << " from StartMenu going to: "<<_game_state << std::endl;

                _main_menu.disable_menu(); // redundant
            }

        break;
        
        case GameState::MapMenu:

            _level_menu.handle_events(_window, event);
            _game_state = _level_menu.get_state();
            std::cout<< "next state: " << _game_state << std::endl;

            // check game state transition
            if(_game_state != GameState::MapMenu){

                std::cout << " from MapMenu going to: "<<_game_state << std::endl;
                _level.make_grid();
                _level.read_file(_level_menu.get_level_to_load());
                _renderer.make_drawable_level(_level);
                _level_menu.disable_menu(); // redundant 
                //std::cout << "MAP LOAD HAPPENS" << std::endl;

            }
        break;

        // paused or round running

        case GameState::Pause:
            _upgrade.handle_events(_window, event);
            _side_menu.handle_events(_window, event);
            _game_state = _side_menu.get_state();
            if(_game_state == GameState::Round){
                std::cout << "in Pause GOING TO round " << std::endl;
                start_round();
            }
        break;

        case GameState::Round:
            // start round button isnt active in sidemenu 
            _side_menu.handle_events(_window, event);
            _upgrade.handle_events(_window, event);
            // no transition from events, transition back to pause when round over
        break;
        
        }
    }
}

// renders current situation on map
void Game::render(){


    switch (_game_state)
    {
    case GameState::StartMenu:
        _window.clear();
        _window.draw(_main_menu);
        _window.display();
        break;

    case GameState::MapMenu:
        _window.clear();
        _window.draw(_level_menu);
        _window.display();
        break;
    
    case GameState::Round:
              // updates moving animations value if it is too high
        if (_enemy_move_animation > 4){
            _enemy_move_animation = 0;
        }
        // because animation are at most five pictures
        // there is for loop until five
        // but basically goes through all attack animations for all attacking objects
        // and through one moving animation for all moving enemies
        // goes through only one moving animation to make moving look more natural when enemy takes only one step at the time
        for (int i = 0; i < 6; i++)
        {
            _window.clear();
            _renderer.draw_level(_window);
            _renderer.draw_towers(_window, _level.get_towers(), i);
            _renderer.draw_enemies(_window, _level.get_enemies(), i, _enemy_move_animation);
            _window.draw(_side_menu);
            _window.draw(_upgrade);

            _window.display(); // display the drawn entities
        }
        _enemy_move_animation++;

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
        break;

    case GameState::Pause:

        //std::cout << "PAUSE STATE HAPPENS" << std::endl;
        // game pause between rounds - no enemies to draw

        _window.clear();
        _renderer.draw_level(_window);
        _renderer.draw_towers(_window, _level.get_towers(), 1);
        _window.draw(_side_menu);
        _window.draw(_upgrade);
        _window.display(); // display the drawn entities
        break;

    case GameState::Victory:

        _window.clear();
        _renderer.draw_end_screen_win(_window);
        _window.display();
        break;

    case GameState::GameOver:

        _window.clear();
        _renderer.draw_end_screen_lose(_window);
        _window.display();
        break;
    }
    
}

// starts new round
void Game::start_round(){
    _round_over = false;
    // Spawns round played ammount multiplied by difficulty level amount of enemies
    for (int i = 0; i < (_difficulty_multiplier * _level.get_round()); i++)
    {
        // Square where enemies can spawn
        Square* spawn_sq = _level.get_first_road();
        // Picks random type of enemy from available types
        int rand_types = rand() % _available_types;
        // Picks random position inside spawn square
        int x = rand() % 80;
        int y = rand() % 40;
        Vector2D rand_pos = Vector2D(spawn_sq->get_center().x - (_level.get_square_size() / 2) + x, 1 + y);
        // add enemy to level
        _level.add_enemy_by_type(rand_types, rand_pos);
    }
    // If available types are under 8, adds new type
    if (_available_types < 7){
        _available_types++;
    }
}

// updates all enemies
void Game::update_enemies(){
    for (Enemy* e : _level.get_enemies()){
        if (e->get_health() <= 0){ // if enemies hp is 0 sets state to dying
            if (e->get_type() == ObjectTypes::BossKnight) { // BossKnight spawns two new skeletons when dies
                _level.add_enemy_by_type(ObjectTypes::NoobSkeleton_NoAttack, e->get_position());
                _level.add_enemy_by_type(ObjectTypes::NoobSkeleton_NoAttack, e->get_position() + Vector2D(5, 5));
            }
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
    for (Tower* t : _level.get_towers()){
        if (t->get_health() <= 0){ // if hp is 0, sets state to dying
            t->set_state(State::dying);
        } else { // if not attacks
            t->attack();
        }
    }
}