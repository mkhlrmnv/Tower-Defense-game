#ifndef Level_HPP
#define Level_HPP

#include "square.hpp"
#include "vector2d.hpp"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

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

    // Load level from file
    int read_file(const std::string& file_name);

    // Saves current level to file
    int save_to_file(const std::string& file_name);

    void print_map();

    void randomly_generate();

private:
    int _square_size;
    int _round, _cash, _lives;
    std::vector<std::vector<Square*>> _grid;
};



#endif