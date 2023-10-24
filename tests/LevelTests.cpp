#include "src/level.hpp"
#include "vector2d.hpp"
#include <iostream>

// tests round count
bool testRound(){
    Level lv(1000, "example_map.txt", 1000, 50); // new level
    for (int i = 0; i < 10; i++) // add 10 rounds to round count
    {
        lv.plus_round();
    }
    return lv.get_round() == 10; // checks if count was correct
}

// tests cash count 
bool testCash(){
    Level lv(1000, "example_map.txt", 1000, 50); // new level
    return lv.get_cash() == 1000; // checks if cash count was correct
}

// tests lives count
bool testLives(){
    Level lv(1000, "example_map.txt", 1000, 50); // new level
    return lv.get_lives() == 1000; // checks if lives count 
}

// test that makeGrid function makes grid that is 10 x 10
bool testGridSize(){
    Level lv(1000, "example_map.txt", 1000, 50); // new level
    lv.make_grid();
    std::vector<std::vector<Square*>> grid = lv.get_grid(); // new grid
    if (grid.size() != 10){ // checks that there is 10 columns
        lv.~Level(); // deletes if not
        return false;
    }
    for (size_t i = 0; i < grid.size(); i++) // checks that every column have 10 squares 
    {
        std::vector<Square*> column = grid[i];
        if (column.size() != 10){
            lv.~Level(); // deletes if not
            return false;
        }
    }
    lv.~Level(); // deletes level
    return true;
}

// checks that makeGrid function initialize squares with right center points
bool testGridSquareCenters(){
    Level lv(1000, "example_map.txt", 1000, 50); // new level
    lv.make_grid();
    std::vector<std::vector<Square*>> grid = lv.get_grid(); // new grid

    int x = 5;
    int y = 5;

    for (size_t i = 0; i < grid.size(); i++) // checks that every square has correct center points
    {
        int current_x = x + (i * 10);
        std::vector<Square*> column = grid[i];
        for (size_t j = 0; j < column.size(); i++)
        {
            int current_y = y + (j * 10);
            Vector2D current_center(current_x, current_y);
            if (column[j]->get_center() == current_center){
                lv.~Level(); // deletes if not
                return false;
            }
        }
    }
    lv.~Level(); // deletes when test is over
    return true;
}

// TODO: Test for read and write to file

int main(){
    int fails = 0;

    if (testRound()){
        std::cout << "testRound: Passed" << std::endl;
    } else {
        std::cout << "testRound: Failed" << std::endl;
    }

    if (testCash()){
        std::cout << "testCash: Passed" << std::endl;
    } else {
        std::cout << "testCash: Failed" << std::endl;
    }

    if (testLives()){
        std::cout << "testLives: Passed" << std::endl;
    } else {
        std::cout << "testLives: Failed" << std::endl;
    }

    if (testGridSize()){
        std::cout << "testGridSize: Passed" << std::endl;
    } else {
        std::cout << "testGridSize: Failed" << std::endl;
    }

    if (testGridSquareCenters()){
        std::cout << "testGridSquareCenters: Passed" << std::endl;
    } else {
        std::cout << "testGridSquareCenters: Failed" << std::endl;
    }
}