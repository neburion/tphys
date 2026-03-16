#pragma once
#include "Angle.hpp"
#include "Vector2D.hpp"
#include "Shape.hpp"

class Object{
    friend class World;
private:
    double mass;
    double inverseMass;

    double restitution; // bounciness
    double friction;

    Vector2D position;
    Angle orientation;
    Vector2D velocity;
    double angularVel;

    Vector2D netForce;
    double netTorque;

    Shape shape;
};
