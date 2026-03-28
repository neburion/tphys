#pragma once
#include "Geometry/Angle.hpp"
#include <cmath>

class Vector;

class Point{
public:
    Point(double x, double y): x(x), y(y){}

    Point rotated(const Angle& rotation) const {
        Point rotated = *this;
        rotated.rotate(rotation);
        return rotated;
    }
    
    // Rotation Matrix
    void rotate(const Angle& rotation){
        double radians   = rotation.getRadians();
        double cosR      = cos(radians);
        double sinR      = sin(radians);

        double originalX = x;
        x = originalX * cosR - y * sinR;
        y = originalX * sinR + y * cosR;
    }

    double x;
    double y;
};
