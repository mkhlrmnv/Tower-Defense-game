// Vector2D.hpp

#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

class Vector2D {
public:
    int x;
    int y;

    Vector2D() : x(0), y(0) {}
    Vector2D(int x, int y) : x(x), y(y) {}

    bool operator==(const Vector2D& other) const {
        return (x == other.x && y == other.y);
    }

    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }
};

#endif
