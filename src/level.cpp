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

bool Level::can_go_notfirst(Direction dir, std::vector<Direction> dir_list){
    size_t list_size = dir_list.size();
    switch (dir)
    {
    case up:
        if (dir_list[list_size - 1] == down && dir_list[list_size - 2] == down) {
            return false;
        }
        break;
    case down:
        if (dir_list[list_size - 1] == up && dir_list[list_size - 2] == up) {
            return false;
        }
        break;
    case right:
        if (dir_list[list_size - 1] == right && dir_list[list_size - 2] == right){
            return false;
        }
    break;
    case left:
        if (dir_list[list_size - 1] == left && dir_list[list_size - 2] == left){
            return false;
        }
        break;
    default:
        break;
    }
    return true;
}

bool Level::can_go_first(Direction dir){
    if (dir == left){
        return false;
    }
    return true;
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

    int new_row = currentRow; // initialize variabels for next  row and column
    int new_col = currentCol;

    while (roadLength < 100 && currentCol < 10) {
        // Mark the current square as a road
        _grid[currentRow][currentCol]->occupy_by_road();

        // Randomly choose the next direction (up or down)
        int dirIndex = std::rand() % 4;
        dir = direction[dirIndex];

        // Move to the next square in the chosen direction
        if (prev_dirs.size() == 0 && can_go_first(dir)){
            switch (dir)
            {
            case up:
                new_row++;
                break;
            case down:
                new_row--;
                break;
            case right:
                new_col++;
            default:
                break;
            }
        } else if (prev_dirs.size() != 0 && can_go_notfirst(dir, prev_dirs)) {
            switch (dir)
            {
            case up:
                new_row++;
                break;
            case down:
                new_row--;
                break;
            case right:
                new_col++;
            case left:
                if (cout_left < max_left){
                    new_col--;
                    cout_left++;
                }
            default:
                break;
            }
        }

        // Check if the new square is within the grid boundaries
        if (new_row >= 0 && new_row < 10 && new_col >= 0 && new_col < 10){
            currentCol = new_col;
            currentRow = new_row;
            prev_dirs.push_back(dir);
        } 
        roadLength++;
    }
}

