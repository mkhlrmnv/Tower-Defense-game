#ifndef Level_HPP
#define Level_HPP

#include "square.hpp"

#include <vector>
#include <string>

class Level {
public:
    Level(int resolution, std::string level, int cash, int lives);

    ~Level();

    const int get_Round() const;

    const int get_Cash() const;

    const int get_Lives() const;

    const void calculate_Size(int res) const;

private:
    int _square_size;
    std::string _level_type;
    int _round, _cash, _lives;
    std::vector<std::vector<Square>> _grid;
};



#endif