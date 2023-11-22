#include "level.hpp"
#include "basic_enemy.hpp"
#include "basic_tower.hpp"

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

int Level::get_square_size() const{
    return _square_size;
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

// Functions below handels everything related to cash, round, etc. 
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

std::vector<Enemy*> Level::get_enemies() const{
    return _enemies;
}

// functions below handels everythign related to enemies and vector of them
bool Level::add_enemy(Enemy* enemy){
    int col = floor(enemy->get_position().x / _square_size);
    int row = floor(enemy->get_position().y / _square_size);
    if (_grid[col][row]->get_occupied() == road){
        _enemies.push_back(enemy);
        return true;
    }
    return false;
}

bool Level::add_enemy_by_type(int type, Vector2D pos){
    return add_enemy(new Basic_Enemy(*this, pos));
}

bool Level::remove_enemy(Enemy* enemy){
    for (size_t i = 0; i < _enemies.size(); i++)
    {
        if (_enemies[i]->get_position() == enemy->get_position() && _enemies[i]->get_health() == enemy->get_health()){
            delete _enemies[i];
            _enemies.erase(_enemies.begin() + i);
            return true;
        }
    }
    return false;
}

std::vector<Tower*> Level::get_towers() const{
    return _towers;
}

// Functions below handels everything related to towers
bool Level::add_tower(Tower* tower){
    int row = floor(tower->get_position().y / _square_size);
    int col = floor(tower->get_position().x / _square_size);
    if (_grid[col][row]->occupy_by_tower()){
        _towers.push_back(tower);
        return true;
    }
    return false;
}

bool Level::add_tower_by_type(int type, Vector2D pos){
    return add_tower(new Basic_Tower(*this, pos));
}

bool Level::remove_tower(Tower* tower){
    for (size_t i = 0; i < _towers.size(); i++)
    {
        if (_towers[i]->get_position() == tower->get_position()){
            delete _towers[i];
            _towers.erase(_towers.begin() + i);
            return true;
        }
    }
    return false;
}

// returns pair where first is current column and second is current row
std::pair<int, int> Level::current_row_col(Object* obj){
    int col = floor(obj->get_position().x / _square_size);
    int row = floor(obj->get_position().y / _square_size);
    return std::make_pair(col, row);
}

// returns square where is object
Square* Level::current_square(Object* obj){
    std::pair<int, int> row_col = current_row_col(obj);
    return _grid[row_col.first][row_col.second];
}

Square* Level::get_square_by_pos(Vector2D pos){
    int col = floor(pos.x / _square_size);
    int row = floor(pos.y / _square_size);
    return _grid[col][row];
}

/* returns vector with directions in which are road squares
Usually size of vector is 2 because if enemy isn't in first or last road square
there are always two ways to go
*/ 
std::vector<Direction> Level::next_road(Enemy* enemy){
    std::pair<int, int> row_col = current_row_col(enemy);
    std::vector<Direction> list_of_road_squares;
    if ((row_col.first + 1) < 10 && _grid[row_col.first + 1][row_col.second]->get_occupied() == road){
        list_of_road_squares.push_back(right);
    }
    if ((row_col.first - 1) >= 0 && _grid[row_col.first - 1][row_col.second]->get_occupied() == road){
        list_of_road_squares.push_back(left);
    }
    if ((row_col.second + 1) < 10  && _grid[row_col.first][row_col.second + 1]->get_occupied() == road){
        list_of_road_squares.push_back(down);
    }
    if ((row_col.second - 1) >= 10 && _grid[row_col.first][row_col.second - 1]->get_occupied() == road){
        list_of_road_squares.push_back(up);
    }
    return list_of_road_squares;
}

void Level::print_objects(){
    for (auto* e : _enemies){
        std::cout << typeid(e).name() << " in point " << e->get_position() << " health: " << e->get_health() << std::endl;
    }
    for (auto* t : _towers){
        std::cout << typeid(t).name() << " in point " << t->get_position()<< " health: " << t->get_health() << std::endl;
    }
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

            // sets variable first road to represent square where is first peace
            // of road
            if (c == '=' && j == 0){
                _first_road = _grid[i][j];
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
    file.close();
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
    file.close();
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
            if (sq->get_occupied() == grass){
                std::cout << "#";
            } else if (sq->get_occupied() == tower){
                std::cout << "T";
            }
            else if (sq->get_occupied() == road){
                std::cout << "=";
            }
        }
        std::cout << std::endl;
    }
}

// ALL BELOW IS FOR randomly_generated function -------------------------------------------------

/*
Function that checks can we move to some direction, in case that 
there is already two squares occupied by road
*/
std::pair<int, int> Level::can_go_notstart(Direction dir, std::vector<Direction> prev_dirs, int row, int col, bool can_go_left){
    std::pair<int, int> pair = std::make_pair(row, col); // makes pair that will be returned with new row and col
    size_t size = prev_dirs.size(); // saves size of list to make if statements smaller
    Direction prev = prev_dirs[size - 1]; // takes previous direction
    Direction sec_prev = prev_dirs[size - 2]; // takes second to previous direction
    switch (dir) // switch case for direction
    {
    case up:
        if (prev != down && sec_prev != down && row != 0){
            /*
            if direction is up and previous and next to previous
            isn't down and if we are not on top row we can move up
            */
            pair.first--;
        }
        break;
    case down:
        if (prev != up && sec_prev != up && row != 9){
            /*
            if direction is down and previous and next to previous
            isn't up and if we are not on bottom row we can move down
            */
            pair.first++;
        }
        break;
    case right:
        if (prev != left && sec_prev != left && col != 9){
            /*
            if direction is right and previous and next to previous
            isn't left and if we are not on last column row we can move right
            */
            pair.second++;
        }
        break;
    case left:
        if (prev != right && sec_prev != right && prev != left && sec_prev != left && col != 0 && can_go_left){
            /*
            if direction is left, previous and next to previous
            isn't right or left, if maximum left steps isn't full
            and if we are not on first col row we can move left
            */
            pair.second--;
        }
        break;
    }
    return pair;
}

/*
Function that checks can we move to some direction, in that there
isn't any squares occupied by road or there is only one square occupied
*/
std::pair<int, int> Level::can_go_start(Direction dir, std::vector<Direction> prev_dirs, int row, int col){
        std::pair<int, int> pair = std::make_pair(row, col);  // makes pair that will be returned with new row and col
        switch (dir) // switch case for direction
        {
        case up:
            if (!prev_dirs.empty() && prev_dirs[0] != down && row != 0){
                /*
                If its not first move, previous direction isn't down
                and its not top row we can move up
                !prev_dirs.empty() is there that program doesn't try to
                call prev_dirs[0] if list is empty
                */
                pair.first--;
            }
            break;
        case down:
            if (!prev_dirs.empty() && prev_dirs[0] != up && row != 9){
                /*
                If its not first move, previous direction isn't up
                and its not bottom row we can move down
                for !prev_dirs.empty() explanation look to up case
                */
                pair.first++;
            }
            break;
        case right:
            // in first two steps, always can move right
            pair.second++;
            break;
        case left:
            // in first two steps, never can go left
            break;
        default:
            break;
        }
    return pair;
}

bool Level::randomly_generate(){
    Direction direction[] = {up, down, right, left}; // list of directions

    int currentRow = 1 + rand() % 7; // Start in the middle row
    int currentCol = 0; // Start from the left side
    int count = 0;
    
    int cout_left = 0;
    int max_left = 4;

    // sets variable first road to represent square where is first peace
    // of road
    _first_road = _grid[currentRow][0];

    Direction dir;
    std::vector<Direction> prev_dirs;

    while (count < 200 || currentCol != 9) {
        // Mark the current square as a road
        _grid[currentRow][currentCol]->occupy_by_road();

        // Randomly choose the next direction (up or down)
        int dirIndex = std::rand() % 4;
        dir = direction[dirIndex - 1];

        std::pair<int, int> pair;

        if (currentRow == 0){
            if (prev_dirs[prev_dirs.size() - 1] == up || prev_dirs[prev_dirs.size() - 2] == up){
                dir = right;
            } else {
                dir = down;
            }
        } else if (currentRow == 9){
            if (prev_dirs[prev_dirs.size() - 1] == down || prev_dirs[prev_dirs.size() - 2]){
                dir = right;
            } else {
                dir = up;
            }
        }

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
        count++;
        if (currentCol == 9){
            _grid[currentRow][currentCol]->occupy_by_road();
            return true;
        }
        //print_map(); // for debugging
        //std::cout << dir << " " << roadLength << std::endl;
        }
    return false;
}

Square* Level::get_first_road(){
    return _first_road;
}