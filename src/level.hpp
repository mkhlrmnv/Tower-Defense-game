#ifndef Level_HPP
#define Level_HPP

#include "square.hpp"
#include "vector2d.hpp"
#include "object.hpp"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

enum Direction{
    up, down, right, left
};

class Level {
public:
    Level(int resolution, int cash, int lives);

    ~Level() {
        for (std::vector<Square*>& column : _grid){
            for (Square* s : column){
                delete s;
            }
            column.clear();
        }
        _grid.clear();

        for(auto& e : _enemies){
            delete e;
        }
        _enemies.clear();

        for (auto* t : _towers){
            delete t;
        }
        _towers.clear();
    }

    // Returns current round
    int get_round() const;

    // Returns current cash
    int get_cash() const;

    // Returns current lives
    int get_lives() const;

    // Returns grid
    std::vector<std::vector<Square*>> get_grid() const;

    // Makes new grid
    void make_grid();

    // Adds round
    void plus_round();

    // Add cash
    void add_cash(int how_much);

    // take cash from player
    void take_cash(int how_much);

    // take lives from player
    void take_lives(int how_much);

    // add lives
    void add_lives(int how_much);

    std::vector<Enemy*> get_enemies() const;

    void add_enemy(Enemy* enemy);

    std::vector<Tower*> get_towers() const;

    void add_tower(Tower* tower);

    // Load level from file
    int read_file(const std::string& file_name);

    // Saves current level to file
    int save_to_file(const std::string& file_name);

    void print_map();

    std::pair<int, int> can_go_notstart(Direction dir, std::vector<Direction> prev_dirs, int row, int col, bool can_go_left);
    std::pair<int, int> can_go_start(Direction dir, std::vector<Direction> dir_list, int row, int col);

    bool randomly_generate();

private:
    int _square_size;
    int _round, _cash, _lives;
    std::vector<std::vector<Square*>> _grid;
    std::vector<Enemy*> _enemies;
    std::vector<Tower*> _towers;
};

std::vector<Enemy*> Level::get_enemies() const{
    return _enemies;
}

std::vector<Tower*> Level::get_towers() const{
    return _towers;
}


#endif