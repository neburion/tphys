#include "rendering/Camera.hpp"
#include "core/Object.hpp"
#include "geometry/Point.hpp"
#include <vector>
#include <ncurses.h>

Camera::Camera(Scene &scene, Point position):
        inViewObjectsIndices(std::vector<int>()),
        scene(scene),
        position(position.x, position.y){
    getmaxyx(stdscr, sizeY, sizeX);
}

int Camera::getObjectsNumber(){
    return inViewObjectsNumber;
}

Object &Camera::getObjectByIndex(int index){
    return scene.getObjectByIndex(index);
}

void Camera::update(){
    getmaxyx(stdscr, sizeY, sizeX);

    int sceneObjectsNumber = scene.getObejectsNumber();
    for(int i = 0; i < sceneObjectsNumber; i++){
        Object &currentObject = scene.getObjectByIndex(i);

        if(currentObject.position.x <= sizeX
        && currentObject.position.y <= sizeY
        && currentObject.position.x >= 0
        && currentObject.position.y >= 0){
            inViewObjectsNumber = scene.getObejectsNumber();
            inViewObjectsIndices.push_back(i);
        }
    }
}
