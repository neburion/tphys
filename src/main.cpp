#include "core/Scene.hpp"
#include "core/Object.hpp"
#include "core/Clock.hpp"
#include "core/Constants.hpp"
#include "core/Physics.hpp"
#include "geometry/Point.hpp"
#include "geometry/Angle.hpp"
#include "geometry/Line.hpp"
#include "geometry/Circle.hpp"
#include "geometry/Polygon.hpp"
#include "rendering/Renderer.hpp"
#include "rendering/Camera.hpp"
#include <ncurses.h>
#include <vector>
#include <memory>

std::vector<Point> makeTestTrianlge(){
    std::vector<Point> points;
    points.push_back(Point(-10, 10));
    points.push_back(Point( 10, 10));
    points.push_back(Point(  0,-10));
    return points;
}

Scene testScene(){
    Scene testScene = Scene();

    Line   line   = Line(Point(1,1),Point(10,10));
    Object o1     = Object("line", std::make_unique<Line>(line),
                           1, 1, 1, 1, Point(1,1), Angle(PI/4));
    testScene.addObject(std::make_unique<Object>(std::move(o1)));
    Circle circle = Circle(10);
    Object o2     = Object("circle", std::make_unique<Circle>(circle),
                           1, 1, 1, 1, Point(25,15), Angle(0));
    testScene.addObject(std::make_unique<Object>(std::move(o2)));
    Polygon polygon = Polygon(makeTestTrianlge());
    Object  o3      = Object("triangle", std::make_unique<Polygon>(polygon),
                             1, 1, 1, 1, Point(35,15), Angle(1));
    testScene.addObject(std::make_unique<Object>(std::move(o3)));

    return testScene;
}

int main(){
    Scene    scene    = testScene();
    Clock    clock    = Clock();
    Physics  physics  = Physics(scene);
    Renderer renderer = Renderer();
    Camera   camera   = Camera(scene, Point(0,0));

    char quitKey   = 'q';
    char rotateKey = 'r';
    char upKey     = 'w';
    char downKey   = 's';
    char leftKey   = 'a';
    char rightKey  = 'd';


    while(1){
        clock.update();
        
        int  controlled = 2;
        char keyPress    = getch();
        
        if(keyPress == quitKey)
            break;
        else if(keyPress == upKey)
            scene.getObjectByIndex(controlled).netForce.setPolar(100, Angle(PI));
        else if(keyPress == downKey)
            scene.getObjectByIndex(controlled).netForce.setPolar(100, Angle(0));
        else if(keyPress == leftKey)
            scene.getObjectByIndex(controlled).netForce.setPolar(100, Angle(3*PI/2));
        else if(keyPress == rightKey)
            scene.getObjectByIndex(controlled).netForce.setPolar(100, Angle(PI/2));
        else if(keyPress == rotateKey)
            scene.getObjectByIndex(controlled).netTorque.setRadians(100);

        while(clock.isTick())
            physics.update();
        if(clock.isFrame()){
            camera.update();
            renderer.drawCamera(camera);
        }
    }

    return 0;
}
