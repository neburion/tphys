#include "Angle.hpp"
#include "Constants.hpp"

Angle::Angle(double radians) : radians(radians) {}

double Angle::getRadians() const {
    return radians;
}
double Angle::getDegrees() const {
    return radians * (180 / PI);
}

void Angle::setRadians(double radians) {
    this->radians = radians;
}
void Angle::setDegrees(double degrees) {
    this->radians = degrees * (PI / 180);
}
