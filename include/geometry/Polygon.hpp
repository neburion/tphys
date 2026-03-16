#pragma once
#include "Shape.hpp"
#include "Vector2D.hpp"
#include <vector>

class Polygon : public Shape{
private:
    std::vector<Vector2D> points;
};
