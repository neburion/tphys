#pragma once
#include "World.hpp"
#include "Camera.hpp"

class Renderer{
public:
    Renderer();

    void draw(const World &world) const;
private:
    Camera camera;
};
