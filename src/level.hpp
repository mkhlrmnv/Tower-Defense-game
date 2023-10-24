#ifndef Level_HPP
#define Level_HPP

#include "square.hpp"
#include "vector2d.hpp"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class Level {
public:
    Level(int resolution, int cash, int lives);

    ~Level() {
        for (std::vector<Square*> column : _grid){
            for (Square* s : column){
                delete s;
            }
            column.clear();
        }
        _grid.clear();
    }

    // Returns current round
    const int get_round() const;

    // Returns current cash
    const int get_cash() const;

    // Returns current lives
    const int get_lives() const;

    // Returns grid
    const std::vector<std::vector<Square*>> get_grid() const;

    // Makes new grid
    void make_grid();

    void plus_round();

    // Load level from file
    int read_file(const std::string& file_name);

    // Saves current level to file
    int save_to_file(const std::string& file_name);

    void randomly_generate();

private:
    int _square_size;
    int _round, _cash, _lives;
    std::vector<std::vector<Square*>> _grid;
};



#endif