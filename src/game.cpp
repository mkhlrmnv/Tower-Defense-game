#include "game.hpp"
#include <thread>
#include <mutex>

// TODO: Some kind of timer in between of round

Game::Game(): 
    _game_resolution(800),
    _side_bar_width(300),
    _window(),
    _level(800, 20000, 50),
    _rh(),
    _renderer(),
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
    generate_chosen_level_style(LevelSelection::load); 

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
    update_enemies();
    update_towers();

    // if there are not any enemies starts new round
    // TODO: Remove this when there are "start round" button
    if (_level.get_enemies().empty() && !round_over) {
        _level.plus_round();
        round_over = true;
        start_round();
    }

    // waits that both threads are ready
    enemiesThread.join();
    towersThread.join();
    _side_menu.update();
}

// Process events in loop:  clicks, button presses
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
        _renderer.draw_enemies(_window, _level.get_enemies(), i);
        _renderer.draw_towers(_window, _level.get_towers(), i);
        _window.draw(_side_menu);
        _window.draw(_upgrade);

        _window.display(); // display the drawn entities
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
        // add enemy to level
        _level.add_enemy_by_type(rand_types, rand_pos);
    }
    // If available types are under 8, adds new type
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