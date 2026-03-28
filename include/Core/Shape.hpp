#pragma once
#include "Geometry/Point.hpp"
#include <vector>

class Shape{
public:
    Shape(std::vector<Point> vertices): vertices(std::move(vertices)) {};

    Point getVertexByIndex(int index) const {return vertices.at(index);};
    int   getVerticesNumber()         const {return (int) vertices.size();}
private:
    const std::vector<Point> vertices;
};
