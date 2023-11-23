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
#include <cmath>


/**
 * @brief Enum for directions
 * 
 * Enum used by randomly_generate, move and etc functions to determine direction where something
 * is going 
 * */
enum Direction{
    up, down, right, left
};


/**
 * @brief Class that controls level of the game
 * 
 * Class holds current grid, all enemies and tower. Also it keeps track of round, money and live situation
 * Level can load hard coded maps from files, save current levels to files or randomly generate fully new one
 * 
 * @param resolution of window
 * @param cash starting cash
 * @param lives starting lives
 */
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

        for (auto* e : _enemies){
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

    // returns size of each square
    int get_square_size() const;

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

    // functions for handling enemies vector
    std::vector<Enemy*> get_enemies() const;
    bool add_enemy(Enemy* enemy);
    bool remove_enemy(Enemy* enemy);
    bool add_enemy_by_type(int type, Vector2D pos);

    // functions for handling towers vector
    std::vector<Tower*> get_towers() const;
    bool add_tower(Tower* tower);
    bool remove_tower(Tower* tower);
    bool add_tower_by_type(int type, Vector2D pos);

    // returns current column and row of object
    std::pair<int, int> current_row_col(Object* obj); // <col, row>

    // returns pointer to current square of object
    Square* current_square(Object* obj);

    // returns pointer to square by position
    Square* get_square_by_pos(Vector2D pos);

    // returns vector, where road continues from current square
    std::vector<Direction> next_road(Enemy* enemy);

    // print all objects
    void print_objects();
    
    // Load level from file
    int read_file(const std::string& file_name);

    // Saves current level to file
    int save_to_file(const std::string& file_name);

    // prints out current map
    void print_map();
    
    // Helper functions for randomly generate
    // One handels situations of first few moves and other all the rest ones
    std::pair<int, int> can_go_notstart(Direction dir, std::vector<Direction> prev_dirs, int row, int col, bool can_go_left);
    std::pair<int, int> can_go_start(Direction dir, std::vector<Direction> dir_list, int row, int col);

    // creates fully random level
    bool randomly_generate();

    // returns first peace of the road
    // Helps enemies to spawn in right place
    Square* get_first_road();

private:
    Square* _first_road;
    int _square_size;
    int _round, _cash, _lives;
    std::vector<std::vector<Square*>> _grid;
    std::vector<Enemy*> _enemies;
    std::vector<Tower*> _towers;
};

#endif
