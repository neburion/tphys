#pragma once
#include "Core/Scene.hpp"
#include "Core/Object.hpp"
#include "Geometry/Vector.hpp"
#include <vector>

struct Collision{
    Vector pointOfContactWorldSpace;
    Vector pointOfContactA;
    Vector pointOfContactB;
    Object &colliderA;
    Object &colliderB;
};

class Physics{
public:
    Physics(Scene &scene);
    
    void                   update();
    void                   calculateNetForce (Object &object);
    void                   calculateNetTorque(Object &object);
    bool                   areColliding      (Object& a, Object& b);
    void                   resolveCollision  (Object  a, Object  b);
    std::vector<Collision> getCollisions();
    void                   resolveCollisions();
private:
    Scene &scene;
};
