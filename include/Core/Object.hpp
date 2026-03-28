#pragma once
#include "Geometry/Angle.hpp"
#include "Geometry/Vector.hpp"
#include "Shape/Shape.hpp"
#include <memory>
#include <string>

class Object{
public:
    Object(const std::string      name,
           std::unique_ptr<Shape> shape,
           double                 mass,
           double                 momentOfInertia,
           double                 restitution,
           double                 friction,
           Point                  position,
           Angle                  orientation);

    const std::string      name;
    std::unique_ptr<Shape> shape;

    const double           mass;            //kg
    const double           momentOfInertia; //??
    const double           restitution;     //?? (bounciness)
    const double           friction;        //??

    Point                  position;        //m,pixel
    Angle                  orientation;     //angle

    Vector                 velocity;        //m,pixel/s
    Angle                  angularVelocity; //angle/s??
    Vector                 netForce;        //N
    Angle                  netTorque;       //??
};
