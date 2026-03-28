#pragma once
#include "Core/Constants.hpp"
#include "Core/Console.hpp"
#include <cmath>

class Angle{
public:
    Angle(double radians) : radians(radians) {normalize();}

    void normalize(){
        radians = fmod(radians, 2*PI);
        if(radians < 0) radians += 2*PI;
    }

    double getRadians() const {return radians;}
    double getDegrees() const {return radians * (180 / PI);}
    Angle  flipped()    const {return Angle(radians + PI);}

    void setRadians(double radians) {
        this->radians = radians;
        normalize();
    }
    void setDegrees(double degrees) {
        this->radians = degrees * (PI / 180);
        normalize();
    }
    void flip() {radians += PI;}

    //auto operator<=>(const Angle& other) const = default;
    Angle& operator+=(const Angle& other){
        radians += other.getRadians();
        normalize();
        return *this;
    }
    Angle& operator-=(const Angle& other){
        radians -= other.getRadians();
        normalize();
        return *this;
    }
    Angle& operator*=(double scalar){
        radians *= scalar;
        normalize();
        return *this;
    }
    Angle& operator/=(double scalar){
        if(scalar == 0){
            Console::log("Division by zero");
            return *this;
        }
        radians /= scalar;
        normalize();
        return *this;
    }
private:
    double radians;
};

inline Angle operator+(Angle  left,   const Angle& right) {return left  += right;}
inline Angle operator-(Angle  left,   const Angle& right) {return left  -= right;}
inline Angle operator*(Angle  angle,  double       scalar){return angle *= scalar;}
inline Angle operator*(double scalar, Angle        angle) {return angle *= scalar;}
inline Angle operator/(Angle  angle,  double       scalar){return angle /= scalar;}
