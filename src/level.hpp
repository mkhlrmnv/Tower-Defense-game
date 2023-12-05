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
    /**
     * @brief Construct a new Level object
     * 
     * @param resolution 
     * @param cash 
     * @param lives 
     */
    Level(int resolution, int cash, int lives);

    /**
     * @brief Destroy the Level object
     */
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

    /**
     * @brief Get current round
     * @return int 
     */
    int get_round() const;

    /**
     * @brief Get current money situation
     * @return int 
     */
    int get_cash() const;

    /**
     * @brief Get current lives
     * @return int 
     */
    int get_lives() const;

    /**
     * @brief Get current the grid
     * @return std::vector<std::vector<Square*>> 
     */
    std::vector<std::vector<Square*>> get_grid() const;

    /**
     * @brief Get the size of each square
     * @return int 
     */
    int get_square_size() const;

    /**
     * @brief Makes new grid
     */
    void make_grid();

    /**
     * @brief 
     */
    void plus_round();

    /**
     * @brief Add money
     * @param how_much How much money want to be added
     */
    void add_cash(int how_much);

    /**
     * @brief Take money from player
     * @param how_much How much money is taken
     */
    void take_cash(int how_much);

    /**
     * @brief Take lives from player
     * @param how_much How much lives is taken
     */
    void take_lives(int how_much);

    /**
     * @brief Add lives
     * @param how_much How much lives is added
     */
    void add_lives(int how_much);

<<<<<<< HEAD
    std::vector<Enemy*> get_enemies() const;

    bool add_enemy(Enemy* enemy);

    std::vector<Tower*> get_towers() const;

    bool add_tower(Tower* tower);

    void print_objects();
    
    // Load level from file
=======
    /**
     * @brief Get the vector of enemies
     * @return std::vector<Enemy*> 
     */
    std::vector<Enemy*> get_enemies() const;

    /**
     * @brief Adds pointer of enemy to vector of all enemies
     * @param enemy Pointer to enemy
     * @return true if is added
     * @return false if not added
     */
    bool add_enemy(Enemy* enemy);

    /**
     * @brief Removes enemy from vector
     * @param enemy pointer to enemy
     * @return true if removed
     * @return false if not removes
     */
    bool remove_enemy(Enemy* enemy);

    /**
     * @brief Makes and adds new enemy by type and position of enemy
     * 
     * @param type type of enemy
     * @param pos position of enemy
     * @return true if added
     * @return false if not added
     */
    bool add_enemy_by_type(int type, Vector2D pos);

    /**
     * @brief Get the vector of towers
     * @return std::vector<Tower*> 
     */
    std::vector<Tower*> get_towers() const;

    /**
     * @brief Adds tower to vector of all towers
     * @param tower Pointer to tower
     * @return true if added
     * @return false if not added
     */
    bool add_tower(Tower* tower);

    /**
     * @brief Removes tower from vector of all towers
     * @param tower Pointer to tower
     * @return true if added
     * @return false if not added
     */
    bool remove_tower(Tower* tower);

    /**
     * @brief Makes and adds new tower to vector of all towers
     * @param type type of tower
     * @param pos position of tower
     * @return true if added
     * @return false if not added
     */
    bool add_tower_by_type(int type, Vector2D pos);

    // returns current column and row of object
    /**
     * @brief Returns current column and row of object
     * @param obj Pointer to object
     * @return std::pair<int, int> => <col, row>
     */
    std::pair<int, int> current_row_col(Object* obj);

    /**
     * @brief Returns pointer to current square of object 
     * @param obj Pointer to object
     * @return Pointer to square
     */
    Square* current_square(Object* obj);

    /**
     * @brief Returns pointer to square by position
     * @param pos Position on map
     * @return Pointer to square
     */
    Square* get_square_by_pos(Vector2D pos);

    /**
     * @brief Returns vector, where road continues from current square
     * @param enemy Pointer to enemy
     * @return Vector of all directions where enemy can go
     */
    std::vector<Direction> next_road(Enemy* enemy);

    /**
     * @brief Print all objects
     */
    void print_objects();
    
    /**
     * @brief Load level from file
     * @param file_name Name of file from where map is loaded
     * @return int 1 if maps is loaded and -1 if load failed
     */
>>>>>>> bc314f0c80edd1a43211ae786e65d3543ca5d1d9
    int read_file(const std::string& file_name);

    /**
     * @brief Saves current level to file
     * @param file_name Name of file where map is saved
     * @return int 1 if map is saved and -1 if failed
     */
    int save_to_file(const std::string& file_name);

    /**
     * @brief Prints out current map
     */
    void print_map();
    
    // Helper functions for randomly generate
    // One handels situations of first few moves and other all the rest ones
    /**
     * @brief Helper functions for randomly generate
     *   Handels situation where it's not few of first round
     * @param dir Direction where randomly generate wants to go
     * @param prev_dirs Vector of all previous directions
     * @param row Current row
     * @param col Current col
     * @param can_go_left Restricts how many time function can go left
     * @return std::pair<int, int> Returns pair of next row and column
     */
    std::pair<int, int> can_go_notstart(Direction dir, std::vector<Direction> prev_dirs, int row, int col, bool can_go_left);

    /**
     * @brief Helper functions for randomly generate
     *   Handels situation where its first few moves
     * @param dir Direction where randomly generate wants to go
     * @param prev_dirs Vector of all previous directions
     * @param row Current row
     * @param col Current col
     * @return std::pair<int, int> Returns pair of next row and column
     */
    std::pair<int, int> can_go_start(Direction dir, std::vector<Direction> dir_list, int row, int col);

    /**
     * @brief Creates fully random level
     * @return true If it was successful 
     * @return false If it wasn't
     */
    bool randomly_generate();

    /**
     * @brief Returns first peace of the road
     *  Helps enemies to spawn in right place
     * @return Square* Pointer of square where first road is
     */
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
