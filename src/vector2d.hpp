#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <iostream>

/**
 * @brief class for in game coordinates
 */
class Vector2D {
public:
    int x;
    int y;

    Vector2D() : x(0), y(0) {}
    /**
     * @brief Construct a new Vector 2 D object
     * @param x 
     * @param y 
     */
    Vector2D(int x, int y) : x(x), y(y) {}

    /**
     * @brief Overriding ==
     * @param other other Vector2D that current is matched with
     * @return true if two Vector2D are identical
     * @return false if they are not
     */
    bool operator==(const Vector2D& other) const {
        return (x == other.x && y == other.y);
    }

    /**
     * @brief Overriding !=
     * @param other other Vector2D that current isn't matched with
     * @return true if two Vector2D aren't identical
     * @return false if they are identical
     */
    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }

    /**
     * @brief Overriding addition operator (+) for Vector2D objects.
     * 
     * @param other Vector2D object to be added to the current Vector2D.
     * @return Vector2D Resultant Vector2D object after addition.
     */
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    /**
     * @brief Overriding subtraction operator (-) for Vector2D objects.
     * 
     * @param other Vector2D object to be subtracted from the current Vector2D.
     * @return Vector2D Resultant Vector2D object after subtraction.
     */
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    
    /**
     * @brief Overriding <<
     * @param os where output is given
     * @param vec Vector2D that information is beeing printed
     * @return std::ostream& new line in console with information about this vector
     * in format "x y"
     */
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
        os << vec.x << " " << vec.y;
        return os;
    }
};

#endif
