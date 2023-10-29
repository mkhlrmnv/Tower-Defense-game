#include "level.hpp"

// Initialize new level
Level::Level(int resolution, int cash, int lives):
    _square_size(resolution/10), _round(0), _cash(cash), _lives(lives) { }

// Returns current round
int Level::get_round() const {
    return _round;
}

// Returns current cash
int Level::get_cash() const {
    return _cash;
}

// Returns current lives
int Level::get_lives() const {
    return _lives;
}

// Returns current grid
std::vector<std::vector<Square*>> Level::get_grid() const{
    return _grid;
}

// Adds one round
void Level::plus_round() {
    _round++;
}

// Makes new grid
void Level::make_grid() {
    if (!_grid.empty()){ // Deletes current grid if its not empty
       for (std::vector<Square*> column : _grid){
            for (Square* s : column){
                delete s;
            }
            column.clear();
        }
        _grid.clear();
    }
    for (int i = 0; i < 10; i++) // counts from 0 -> 9 to make 10 columns
    { 
        std::vector<Square*> new_column; // makes new column
        for (int j = 0; j < 10; j++) // counts from 0 -> 9 to make 10 squares in each column
        {
            Vector2D cords;
            cords.x = (_square_size / 2) + (i * _square_size); //calculates cordinates8 for square center
            cords.y = (_square_size / 2) + (j * _square_size);
            new_column.push_back(new Square(cords)); // adds new square to current column
        }
        _grid.push_back(new_column); // add just created column to grid
    } 
}

void Level::add_cash(int how_much){
    _cash += how_much;
}

void Level::take_cash(int how_much){
    _cash -= how_much;
}

void Level::add_lives(int how_much){
    _lives += how_much;
}

void Level::take_lives(int how_much){
    _lives -= how_much;
}

// Initialize map from file
int Level::read_file(const std::string& file_name){
    std::ifstream file(file_name);  // opens file

    if (!file.is_open()){ // checks if file is open, if isn't return -1
        return -1;
    }

    for (int i = 0; i < 10; i++) // counts 0 -> 9, because there is 10 columns
    {
        for (int j = 0; j < 10; j++) // counts 0 -> 9 because there is 10 squares in each column
        {
            char c = file.get(); // takes on char from file

            if (c != '#' && c != '='){ // if char isn't # or = takes next one
                c = file.get();
            }

            if (c == '#'){
                _grid[i][j]->occupy_by_grass(); // if char is # occupy square with grass
            } 
            else if (c == '='){
                _grid[i][j]->occupy_by_road(); // if char is = occupy square with road
            } else {
                return -1; // if isn't any of those two return -1 because read failed
            }
        } 
    }
    return 1;
}

// Saves current map to file
int Level::save_to_file(const std::string& file_name){
    std::ofstream file(file_name); // opens file

    if (!file.is_open()){ // checks if file is open, if isn't return -1
        return -1;
    }
    
    for (size_t i = 0; i < _grid.size(); i++)
    {
        for (size_t j = 0; j < _grid.size(); j++)
        { // checks what every square is occupied by and writes charecter depending on that
            Square* sq = _grid[i][j];
            if (sq->get_occupied() == grass || sq->get_occupied() == tower){
                file << "#";
                } 
            else if (sq->get_occupied() == road){
                file << "=";
            }
        }
        if (i < 9){
            file << std::endl;
        }
    }
    return 1;
}

// Prints current map
void Level::print_map(){
    if (_grid.empty()){ // checks if there is existing grid
        std::cout << "There isn't map to print" << std::endl;
        return;
    }
    for (size_t i = 0; i < _grid.size(); i++)
    {
        for (size_t j = 0; j < _grid.size(); j++) 
        { // checks what every square is occupied by and prints charecter depending on that
            Square* sq = _grid[i][j]; 
            if (sq->get_occupied() == grass || sq->get_occupied() == tower){
                std::cout << "#";
            } 
            else if (sq->get_occupied() == road){
                std::cout << "=";
            }
        }
        std::cout << std::endl;
    }
}

// ALL BELOW IS FOR randomly_generated function

std::pair<int, int> Level::can_go_notstart(Direction dir, std::vector<Direction> prev_dirs, int row, int col, bool can_go_left){
    std::pair<int, int> pair = std::make_pair(row, col);
    size_t size = prev_dirs.size();
    Direction prev = prev_dirs[size - 1];
    Direction sec_prev = prev_dirs[size - 2];
    switch (dir)
    {
    case up:
        if (prev != down && sec_prev != down && row != 0){
            pair.first--;
        }
        break;
    case down:
        if (prev != up && sec_prev != up && row != 9){
            pair.first++;
        }
        break;
    case right:
        if (prev != right && sec_prev != right && prev != left && sec_prev != left && col != 9){
            pair.second++;
        }
        break;
    case left:
        if (prev != right && sec_prev != right && prev != left && sec_prev != left && col != 0 && can_go_left){
            pair.second--;
        }
        break;
    }
    return pair;
}

std::pair<int, int> Level::can_go_start(Direction dir, std::vector<Direction> prev_dirs, int row, int col){
        std::pair<int, int> pair = std::make_pair(row, col);  // <row, col>
        switch (dir) 
        {
        case up:
            if (prev_dirs.empty() && row != 0){
                pair.first--;
            } else if (!prev_dirs.empty() && prev_dirs[0] != down && row != 0){
                pair.first--;
            }
            break;
        case down:
            if (prev_dirs.empty() && row != 10){
                pair.first++;
            } else if (!prev_dirs.empty() && prev_dirs[0] != up && row != 9){
                pair.first++;
            }
            break;
        case right:
            pair.second++;
            break;
        case left:
            if (!prev_dirs.empty() && prev_dirs[0] != right){
                pair.second++;
            }
        default:
            break;
        }
        return pair;
}

void Level::randomly_generate(){
    srand((unsigned int)time(NULL)); // makes rand() more random
    Direction direction[] = {up, down, right, left}; // list of directions

    int currentRow = 1 + rand() % 7; // Start in the middle row
    int currentCol = 0; // Start from the left side
    int roadLength = 0;
    
    int cout_left = 0;
    int max_left = 4;

    Direction dir;
    std::vector<Direction> prev_dirs;

    while (currentCol != 9) {
        // Mark the current square as a road
        _grid[currentRow][currentCol]->occupy_by_road();

        // Randomly choose the next direction (up or down)
        int dirIndex = std::rand() % 4;
        dir = direction[dirIndex - 1];

        std::pair<int, int> pair;

        // Move to the next square in the chosen direction
        if (prev_dirs.size() < 2){
            pair = can_go_start(dir, prev_dirs, currentRow, currentCol);
        } else if (prev_dirs.size() >= 2) {
            pair = can_go_notstart(dir, prev_dirs, currentRow, currentCol, cout_left < max_left);
        }  

        if (pair.first != currentRow || pair.second != currentCol){
            currentRow = pair.first;
            currentCol = pair.second;
            prev_dirs.push_back(dir);
        }
        roadLength++;
        print_map();
        std::cout << dir << roadLength << std::endl;
    }
}

