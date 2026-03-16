#pragma once

class Angle{
public:
    Angle(double radians);

    double getRadians() const;
    double getDegrees() const;

    void setRadians(double radians);
    void setDegrees(double degrees);

private:
    double radians;
};
