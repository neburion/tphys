#pragma once
#include "Vector2D.hpp"

class Camera{
public:
    Vector2D worldToScreen(const Vector2D &point) const;
private:
    Vector2D position;
    double zoom;
};
