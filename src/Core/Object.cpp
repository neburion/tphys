#include "core/Object.hpp"
#include "geometry/Angle.hpp"
#include "geometry/Vector.hpp"

Object::Object(const std::string      name,
               std::unique_ptr<Shape> shape,
               double                 mass,
               double                 momentOfInertia,
               double                 restitution,
               double                 friction,
               Point                  position,
               Angle                  orientation) :
    name           (name),
    shape          (std::move(shape)),

    mass           (mass),
    momentOfInertia(momentOfInertia),
    restitution    (restitution),
    friction       (friction),

    position       (position.x, position.y),
    orientation    (orientation),
    velocity       (Vector(0,0)),
    angularVelocity(Angle(0)),
    netForce       (Vector(0,0)),
    netTorque      (Angle(0))
{}
