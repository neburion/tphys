#pragma once
#include "Geometry/Angle.hpp"
#include "Geometry/Point.hpp"
#include "Core/Console.hpp"
#include <cmath>

class Vector{
public:
    Vector(double x, double y): x(x), y(y) {}

    double getMagnitude() const {return sqrt(x*x + y*y);}
    Angle  getAngle()     const {return atan2(y, x);}
    Vector rotated(const Angle& rotation) const {
        Vector rotated = *this;
        rotated.rotate(rotation);
        return rotated;
    }

    void setZero(){
        x = 0;
        y = 0;
    }
    void setPolar(double magnitude, const Angle& angle){
        double radians = angle.getRadians();
        x = magnitude * cos(radians);
        y = magnitude * sin(radians);
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
    void setFromPoint(const Point& origin);

    Vector& operator*=(double scalar){
        x*= scalar;
        y*= scalar;
        return *this;
    }
    Vector& operator/=(double scalar){
        if(scalar != 0){
            x/= scalar;
            y/= scalar;
        }
        else Console::log("Division by zero");
        return *this;
    }
    Vector& operator+=(const Vector& origin){
        x+= origin.x;
        y+= origin.y;
        return *this;
    }
    Vector& operator+=(const Point& origin);
    
    double x;
    double y;
};

inline Vector operator*(Vector vector, double scalar)       {return vector*= scalar;}
inline Vector operator/(Vector vector, double scalar)       {return vector/= scalar;}
inline Vector operator+(Vector origin, const Vector& offset){return origin+= offset;}
Point  operator+(Point origin, const Vector& offset);
