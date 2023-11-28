#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "vector2d.hpp"
#include "object.hpp"
#include <iostream>
#include "tower.hpp"
#include "enemy.hpp"

#include <vector>

/**
 * @brief Enum for different states of occupied of square
 * Basically for knowing what this square has inside. Is it road 
 * so enemies can go there, is it empty grass square so program can put there tower
 * or is it tower so nothing can be placed there
 */
enum occupied_type{
    grass, road, tower
};

/**
 * @brief Class for squares that makes grid of level
 * @param center cordinates of squares center point in Vector2D
 */
class Square {
public:
    /**
     * @brief Construct a new Square object
     * @param center cordinates in Vector2D where are square center
     */
    Square(Vector2D center);

    /**
     * @brief Destroy the Square object
     */
    ~Square() { }

    /**
     * @brief Returns center cordinates of square
     * @return Vector2D 
     */
    Vector2D get_center() const;
    /**
     * @brief Returns what is occupying square
     * @return int = enum occupied_by
     */
    int get_occupied() const;

    /**
     * @brief Prints info of square
     * What is squares center point and by what square
     * is occupied
     */
    void print_info();

    // Occupies square by something
    /**
     * @brief Function to occupy square by grass
     * @return true if was successful
     * @return false if wasn't
     */
    bool occupy_by_grass();

    /**
     * @brief Function to occupy square by road
     * @return true if was successful
     * @return false if wasn't
     */
    bool occupy_by_road();

    /**
     * @brief Function to occupy square by tower
     * @return true if was successful
     * @return false if wasn't
     */
    bool occupy_by_tower();

private:
    Vector2D _center;
    occupied_type _occupied_by;
};


#endif