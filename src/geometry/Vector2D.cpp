#include "Vector2D.hpp"
#include <cmath>

Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

double Vector2D::magnitudeSquared() const {
    return x*x + y*y;
}
double Vector2D::magnitude() const {
    return sqrt(magnitudeSquared());
}
Angle Vector2D::angle() const {
    return Angle(atan2(y, x));
}
