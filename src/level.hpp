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
    Level(int resolution, std::string level, int cash, int lives);

    ~Level() {
        for (std::vector<Square*> collumn : _grid){
            for (Square* s : collumn){
                delete s;
            }
            collumn.clear();
        }
        _grid.clear();
    }

    // Returns current round
    const int get_Round() const;

    // Returns current cash
    const int get_Cash() const;

    // Returns current lives
    const int get_Lives() const;

    // Returns grid
    const std::vector<std::vector<Square*>> get_Grid() const;

    // Makes new grid
    void make_Grid();

    void plus_Round();

    // Load level from file
    int read_file(const std::string& file_name);

    // Saves current level to file
    int save_to_file(const std::string& file_name);

    void randomly_generate();

private:
    int _square_size;
    std::string _level_type;
    int _round, _cash, _lives;
    std::vector<std::vector<Square*>> _grid;
};



#endif