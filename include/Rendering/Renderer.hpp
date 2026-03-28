#pragma once
#include "Core/Object.hpp"
#include "rendering/Camera.hpp"

class Renderer{
public:
    Renderer();
    ~Renderer();

    void  drawPoint(double x,double y);
    void  drawLine(Point pointA, Point pointB);
    void  drawObject(Object &toDraw);
    void  drawCamera(Camera &inViewScene);
};
