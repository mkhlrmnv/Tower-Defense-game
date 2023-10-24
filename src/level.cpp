#include "level.hpp"

Level::Level(int resolution, std::string level, int cash, int lives):
    _square_size(resolution/10), _level_type(level), _round(0), _cash(cash), _lives(lives) { }

const int Level::get_Round() const {
    return _round;
}

const int Level::get_Cash() const {
    return _cash;
}

const int Level::get_Lives() const {
    return _lives;
}

const Level::std::vector<std::vector<Square*>> get_Grid() const{
    return _
}

void Level::plus_Round() {
    _round++;
}

void Level::make_Grid() {
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; i++)
        {
            Vector2D cords;
            cords.x = (_square_size / 2) + (i * _square_size);
            cords.y = (_square_size / 2) + (j * _square_size);
            _grid[i][j] = new Square(cords);
        }
    } 
}

int Level::read_file(const std::string& file_name){
    std::ifstream file(file_name);

    if (!file.is_open()){
        return -1;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; i++)
        {
            char c = file.get();
            if (c == '#'){
                _grid[i][j]->occupy_by_grass();
            } 
            else if (c == '='){
                _grid[i][j]->occupy_by_road();
            }
        }
        
    }
    return 1;
}

int Level::save_to_file(const std::string& file_name){
    std::ofstream file(file_name);

    if (!file.is_open()){
        return -1;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; i++)
        {
            if (_grid[i][j]->get_Occupied() == grass){
                file << "#";
            }
            else if (_grid[i][j]->get_Occupied() == road || _grid[i][j]->get_Occupied() == tower){
                file << "=";
            }
        }
        if (i != 9){
            file << "\n";
        }
    }
}

