#pragma once
#include "Angle.hpp"

class Vector2D{
public:
    Vector2D(double x, double y);

    double magnitudeSquared() const;
    double magnitude() const;
    Angle angle() const;

    double x;
    double y;
};
