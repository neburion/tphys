#include "geometry/Vector.hpp"
#include "geometry/Point.hpp"

void Vector::setFromPoint(const Point& origin){
    x+= origin.x;
    y+= origin.y;
}

Vector& Vector::operator+=(const Point& origin){
    x+= origin.x;
    y+= origin.y;
    return *this;
}

Point operator+(Point origin, const Vector& offset){
    origin.x+= offset.x;
    origin.y+= offset.y;
    return origin;
}
