#include "game.hpp"
#include <thread>
#include <mutex>
#include "constants.hpp"

std::mutex enemiesMutex;
std::mutex enemiesMutex_2;
std::mutex towersMutex;

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
        if(_level.read_file(Constants::path_to_project + "maps/example_map.txt")==-1){
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

    auto t1_pos = Vector2D(82*5, 1*80);
    auto t2_pos = Vector2D(82*5, 2*80);
    auto t3_pos = Vector2D(82*5, 3*80);
    auto t4_pos = Vector2D(82*3, 1*80);
    auto t5_pos = Vector2D(82*3, 2*80);
    auto t6_pos = Vector2D(82*3, 3*80);

    // Tower(level, health, damage, range, attack_speed, pos, type, price, level, single or not)
    _level.add_tower(new Basic_Tower(_level, t1_pos, 30, 10, 100, 1, 0, 100, 1, true));
    _level.add_tower(new Basic_Tower(_level, t2_pos, 30, 10, 100, 1, 1, 100, 1, true));
    _level.add_tower(new Basic_Tower(_level, t3_pos, 30, 10, 100, 1, 2, 100, 1, true));
    _level.add_tower(new Basic_Tower(_level, t4_pos, 30, 10, 100, 1, 3, 100, 1, true));
    _level.add_tower(new Basic_Tower(_level, t5_pos, 30, 10, 100, 1, 4, 100, 1, true));
    _level.add_tower(new Basic_Tower(_level, t6_pos, 30, 10, 100, 1, 5, 100, 1, true));

    _renderer.make_drawable_level(_level);
    _renderer.make_drawable_object_textures();
    _renderer.make_level_info_texts(_game_resolution, _side_bar_width);




    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (_window.isOpen())
    {
        process_events();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > sf::seconds(1.f / 60.f))
        {
            timeSinceLastUpdate -= sf::seconds(1.f / 60.f);
            process_events();
            update();
            render();
        }
    }
}

void Game::update(){

    std::thread enemiesThread(&Game::update_enemies, this);
    std::thread towersThread(&Game::update_towers, this);

    // if there are not enemies and round over variable hasn't been updates
    // new round starts
    if (_level.get_enemies().empty() && !round_over) {
        _level.plus_round();
        round_over = true;
        start_round();
    }

    enemiesThread.join();
    towersThread.join();
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
    for (int i = 0; i < 5; i++)
    {
        _window.clear();
        _renderer.draw_level(_window);
        _renderer.draw_enemies(_window, _level.get_enemies(), i);
        _renderer.draw_towers(_window, _level.get_towers(), i);
         _renderer.draw_cash(_window, _level.get_cash());
        _renderer.draw_lives(_window, _level.get_lives());
        _renderer.draw_round_count(_window, _level.get_round());
        _window.display(); // display the drawn entities

        // std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

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

void Game::start_round(){
    round_over = false;
    for (int i = 0; i < (1 * _level.get_round()); i++)
    {
        // srand (time(0)+1);
        Square* spawn_sq = _level.get_first_road();
        int x = rand() % 80;
        int y = rand() % 40;
        Vector2D rand_pos = Vector2D(spawn_sq->get_center().x - (_level.get_square_size() / 2) + x, 1 + y);
        _level.add_enemy(new Basic_Enemy(_level, rand_pos));
    }
    // Enemy(level, health, damage, range, attack_speed, pos, type, speed, defense)
}

void Game::update_enemies(){
    std::lock_guard<std::mutex> lock(enemiesMutex);
    for (Enemy* e : _level.get_enemies()){
        if (e->get_health() <= 0){
            e->set_state(State::dying);
            // _level.remove_enemy(e);
        } else {
            if (!e->attack()){
                e->move();
            }
        }
    }
}

void Game::update_towers(){
    std::lock_guard<std::mutex> lock(towersMutex);
    for (Tower* t : _level.get_towers()){
        if (t->get_health() <= 0){
            t->set_state(State::dying);
            // _level.remove_tower(t);
        } else {
            t->attack();
        }
    }
}