#include "level.hpp"
#include "object.hpp"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// tests round count
bool testRound(){
    Level lv(1000, 1000, 50); // new level
    int random_int = rand() % 10;
    for (int i = 0; i < random_int; i++) // add random amount of rounds
    {
        lv.plus_round();
    }
    return lv.get_round() == random_int; // checks if count was correct
}

// tests cash count 
bool testCash(){
    Level lv(1000, 1000, 50); // new level
    int random_int = rand() % 500; // add some random number of cash
    lv.add_cash(random_int);
    int random_int2 = rand() % 100; // take some random number of cash
    lv.take_cash(random_int2);
    return lv.get_cash() == (1000 + random_int - random_int2); // checks if cash count was correct
}

// tests lives count
bool testLives(){
    Level lv(1000, 1000, 50); // new level
    int random_int = rand() % 25;
    lv.take_lives(random_int); // Minuses random amount of money
    int random_int2 = rand() % 10;
    lv.add_lives(random_int2); // add random amount of money
    return lv.get_lives() == (50 - random_int + random_int2); // checks if lives count 
}

bool testObjectList(){
    std::string file_name = "maps/example_map.txt"; // file name of the map test map
    Level lv(1000, 1000, 50); // new level
    lv.make_grid(); 
    lv.read_file(file_name);

    Vector2D pos = Vector2D(150, 450); // should fail
    Tower* t = new Tower(10, 10, 10, 10, pos, 10);

    Vector2D pos2 = Vector2D(50, 50); // should pass
    Tower* t2 = new Tower(10, 10, 10, 10, pos2, 10);

    Vector2D pos3 = Vector2D(350, 350); // should fail
    Enemy* e = new Enemy(10, 10, 10, 10, pos3, 10, 1);

    Vector2D pos4 = Vector2D(150, 455); // should pass
    Enemy* e2 = new Enemy(10, 10, 10, 10, pos4, 10, 1);   

    return !lv.add_tower(t) && lv.add_tower(t2) && !lv.add_enemy(e) && lv.add_enemy(e2);
}

// test that makeGrid function makes grid that is 10 x 10
bool testGridSize(){
    Level lv(1000, 1000, 50); // new level
    lv.make_grid();
    std::vector<std::vector<Square*>> grid = lv.get_grid(); // new grid
    if (grid.size() != 10){ // checks that there is 10 columns
        return false; // returns false if not
    }
    for (size_t i = 0; i < grid.size(); i++) // checks that every column have 10 squares 
    {
        std::vector<Square*> column = grid[i];
        if (column.size() != 10){
            return false; // returns false if not
        }
    }
    return true;
}

// checks that makeGrid function initialize squares with right center points
bool testGridSquareCenters(){
    Level lv(1000, 1000, 50); // new level
    lv.make_grid();
    std::vector<std::vector<Square*>> grid = lv.get_grid(); // new grid
    int x = 5; // cordinates for first square center
    int y = 5;
    for (size_t i = 0; i < grid.size(); i++) // checks that every square has correct center points
    {
        int current_x = x + (i * 10); // calculates what x should be
        std::vector<Square*> column = grid[i];
        for (size_t j = 0; j < column.size(); j++)
        {
            int current_y = y + (j * 10); // calculates what y should be
            Vector2D current_center(current_x, current_y); // makes correct cordinates
            if (column[j]->get_center() == current_center){ // compares if cordinates matches
                //lv.~Level(); // deletes if not
                return false;
            }
        }
    }
    //lv.~Level(); // deletes when test is over
    return true;
}

// Test for read and write to file

bool testRead(){
    std::string file_name = "maps/example_map.txt"; // file name of the map test map
    Level lv(1000, 1000, 50); // new level
    lv.make_grid(); 
    lv.read_file(file_name); // reads new map from test map file
    std::vector<std::vector<Square*>> grid = lv.get_grid(); 
    std::ifstream file(file_name);
    for (size_t i = 0; i < grid.size(); i++) // compares grid to test map file
    {
        std::string line;
        std::getline(file, line);
        std::vector<Square*> column = grid[i];
        for (size_t j = 0; j < column.size(); j++)
        {
            if (line[j] == '#' && column[j]->get_occupied() == road){
                return false;
            }
        }
    }
    return true;
}

bool testWrite(){
    std::string file_name = "maps/example_map.txt"; // file name for reading
    std::string file_name_w = "maps/example_map_w.txt"; // file name for writing
    Level lv(1000, 1000, 50); // new level
    lv.make_grid();
    lv.read_file(file_name); // reads maps from file
    lv.save_to_file(file_name_w); // writes current map to file
    
    // compares two two files 
    std::ifstream f1(file_name, std::ifstream::binary|std::ifstream::ate);
    std::ifstream f2(file_name_w, std::ifstream::binary|std::ifstream::ate);
    
    if (f1.fail() || f2.fail()) {
        return false; //file problem
    }

    if (f1.tellg() != f2.tellg()) {
        return false; //size mismatch
    }

    //seek back to beginning and use std::equal to compare contents
    f1.seekg(0, std::ifstream::beg);
    f2.seekg(0, std::ifstream::beg);
    return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                        std::istreambuf_iterator<char>(),
                        std::istreambuf_iterator<char>(f2.rdbuf()));
}

bool testRandomMap(){
    Level lv(1000, 1000, 50); // new level
    lv.make_grid();
    bool res = lv.randomly_generate();
    lv.print_map();
    return res;
}

/*bool testRandomHelp(){
    Level lv(1000, 1000, 50); // new level
    lv.make_grid();
    std::vector<Direction> list;
    list.push_back(right);
    list.push_back(right);
    bool res = !lv.can_go_notfirst(right, list); // should fail
    list.push_back(left);
    res = lv.can_go_notfirst(right, list); // should pass
    list.clear();
    list.push_back(down);
    list.push_back(down);
    res = !lv.can_go_notfirst(up, list);// should fail
    list.push_back(right);
    res = lv.can_go_notfirst(up, list); // should pass
    list.clear();
    list.push_back(up);
    list.push_back(up);
    res = !lv.can_go_notfirst(down, list); // should fail
    list.push_back(right);
    res = lv.can_go_notfirst(down, list); // should pass
    list.clear();
    list.push_back(left);
    list.push_back(left);
    res = !lv.can_go_notfirst(left, list); // should fail
    list.push_back(right);
    res = lv.can_go_notfirst(left, list); // should pass
    return res;
}*/

/*bool testRandom1(){ // test for can_go_start()
    Level lv(1000, 1000, 50); // new level
    lv.make_grid();
    std::vector<Direction> list;
    std::pair<int, int> pair = lv.can_go_start(right, list, 4, 10);
    std::cout << pair.first << " " << pair.second << std::endl;
    list.push_back(right);
    pair = lv.can_go_start(left, list, 4, 1);
    std::cout << pair.first << " " << pair.second << std::endl;
    list.clear();
    list.push_back(down);
    pair = lv.can_go_start(up, list, 4, 0);
    std::cout << pair.first << " " << pair.second << std::endl;
    list.clear();
    list.push_back(up);
    pair = lv.can_go_start(down, list, 4, 0);
    std::cout << pair.first << " " << pair.second << std::endl;
    return true;
}*/

/*bool testRandom2(){
    Level lv(1000, 1000, 50); // new level
    lv.make_grid();
    std::vector<Direction> list;
    list.push_back(right);
    list.push_back(up);
    std::pair<int, int> pair = lv.can_go_notstart(up, list, 10, 4, true);
    std::cout << pair.first << " " << pair.second << std::endl;

    list.push_back(right);
    list.push_back(down);
    pair = lv.can_go_notstart(down, list, 0, 4, true);
    std::cout << pair.first << " " << pair.second << std::endl;

    list.push_back(up);
    list.push_back(up);
    pair = lv.can_go_notstart(right, list, 4, 10, true);
    std::cout << pair.first << " " << pair.second << std::endl;

    list.push_back(up);
    list.push_back(up);
    pair = lv.can_go_notstart(left, list, 4, 0, true);
    std::cout << pair.first << " " << pair.second << std::endl;

    return true;
}*/

static int level_test(){
    srand((unsigned int)time(NULL)); // makes rand() more random
    int fails = 0;

    if (testRound()){
        std::cout << "testRound: Passed" << std::endl;
    } else {
        std::cout << "testRound: Failed" << std::endl;
        fails++;
    }

    if (testCash()){
        std::cout << "testCash: Passed" << std::endl;
    } else {
        std::cout << "testCash: Failed" << std::endl;
        fails++;
    }

    if (testLives()){
        std::cout << "testLives: Passed" << std::endl;
    } else {
        std::cout << "testLives: Failed" << std::endl;
        fails++;
    }

    if (testGridSize()){
        std::cout << "testGridSize: Passed" << std::endl;
    } else {
        std::cout << "testGridSize: Failed" << std::endl;
        fails++;
    }

    if (testGridSquareCenters()){
        std::cout << "testGridSquareCenters: Passed" << std::endl;
    } else {
        std::cout << "testGridSquareCenters: Failed" << std::endl;
        fails++;
    }

    if (testRead()){
        std::cout << "testRead: Passed" << std::endl;
    } else {
        std::cout << "testRead: Failed" << std::endl;
        fails++;
    }

    if (testWrite()){
        std::cout << "testWrite: Passed" << std::endl;
    } else {
        std::cout << "testWrite: Failed" << std::endl;
        fails++;
    }

    if (testObjectList()){
        std::cout << "testObjectList: Passed" << std::endl;
    } else {
        std::cout << "testObjectList: Failed" << std::endl;
        fails++;
    }
    
    std::cout << "Making random map:" << std::endl;    
    if (testRandomMap()){
        std::cout << "testRandom: Passed" << std::endl;
    } else {
        std::cout << "testRandom: Failed" << std::endl;
    }

    //testRandom2();

    if (fails == 0){
        std::cout << "All Level test passed" << std::endl;
    } else {
        std::cout << fails << " Level test failed" << std::endl;
    }
    
    return fails;
}
