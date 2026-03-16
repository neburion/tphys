#pragma once
#include "Shape.hpp"
#include "Vector2D.hpp"

class Line : public Shape{
private:
    Vector2D a;
    Vector2D b;
};
