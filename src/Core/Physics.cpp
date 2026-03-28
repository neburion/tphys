#include "core/Physics.hpp"
#include "core/Scene.hpp"
#include "core/Object.hpp"
#include "core/Clock.hpp"
#include "geometry/Vector.hpp"
#include <cmath>

Physics::Physics(Scene &scene):scene(scene){}

void Physics::update(){
    for(int i = 0; i < scene.getObejectsNumber(); i++){
        calculateNetForce(scene.getObjectByIndex(i));
        scene.getObjectByIndex(i).position = scene.getObjectByIndex(i).position+
            scene.getObjectByIndex(i).velocity * Clock::deltaTime;

        calculateNetTorque(scene.getObjectByIndex(i));
        scene.getObjectByIndex(i).orientation+=
            scene.getObjectByIndex(i).angularVelocity * Clock::deltaTime;
    }
}

void Physics::calculateNetForce(Object &object){
    double mass              = object.mass;
    Vector currentVelocity   = object.velocity;
    Vector force             = object.netForce;

    Vector acceleration      = Vector(force.x, force.y) / mass;
    Vector newVelocity       = currentVelocity + acceleration * Clock::deltaTime;
    object.velocity          = newVelocity;
    object.netForce.setZero();
}

void Physics::calculateNetTorque(Object &object){
    double momentOfInertia        = object.momentOfInertia;
    Angle  currentAngularVelocity = object.angularVelocity;
    Angle  torque                 = object.netTorque;

    Angle  angularAcceleration    = torque / momentOfInertia;
    Angle  newAngularVelocity     = currentAngularVelocity+
                                     angularAcceleration * Clock::deltaTime;
    object.angularVelocity        = newAngularVelocity;
    object.netTorque.setRadians(0);
}

bool areColliding(Object& a, Object& b){
    return false;
}
