#include "rendering/Renderer.hpp"
#include "geometry/Shape.hpp"
#include "core/Object.hpp"
#include <ncurses.h>
#include <vector>
#include <cmath>

Renderer::Renderer(){
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    nodelay(stdscr, TRUE);
    clear();
}

Renderer::~Renderer(){
    endwin();
}

void Renderer::drawPoint(double x,double y){
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    attron(COLOR_PAIR(1));
    mvwprintw(stdscr, y, x, " ");
    attroff(COLOR_PAIR(1));
}

// the name of the algorithm here
void Renderer::drawLine(Point pointA, Point pointB){
    double dx = pointB.x - pointA.x;
    double dy = pointB.y - pointA.y;
    double step;

    if(std::abs(dy) > std::abs(dx)){
        step = std::abs(dy);
    } else{
        step = std::abs(dx);
    }

    double stepX = dx / step;
    double stepY = dy / step;

    for(int i = 0; i <= step; i++){
        int x = pointA.x + round(i * stepX);
        int y = pointA.y + round(i * stepY);

        drawPoint(y, x);
    }
}

void Renderer::drawObject(Object &toDraw){
    std::span<const Point> vertices   = toDraw.shape->getVertices();
    int                verticesNumber = toDraw.shape->getVerticesNumber();
    Vector             offset         = Vector(toDraw.position.x, toDraw.position.y);
    double             orientation    = toDraw.orientation.getRadians();

    if(toDraw.shape->getDrawMode() == DrawMode::CONNECTED){
        if(verticesNumber < 2)
            mvwprintw(stdscr, vertices[0].y, vertices[0].x, "Error");

        else if(verticesNumber == 2)
            drawLine(vertices[0].rotated(orientation)+offset,
                     vertices[1].rotated(orientation)+offset);

        else{
            for(int i = 0; i < verticesNumber-1; i++)
                drawLine(vertices[i].rotated(orientation)+offset,
                         vertices[i+1].rotated(orientation)+offset);
            drawLine(vertices[0].rotated(orientation)+offset,
                     vertices[verticesNumber-1].rotated(orientation)+offset);
        }
    }

    else if(toDraw.shape->getDrawMode() == DrawMode::POINTS){
        for(int i = 0; i < verticesNumber; i++)
            drawPoint((vertices[i].rotated(orientation)+offset).x,
                      (vertices[i].rotated(orientation)+offset).y);
    }
}

void Renderer::drawCamera(Camera &inViewScene){
    inViewScene.update();
    clear();
    for(int i = 0; i < inViewScene.getObjectsNumber(); i++)
        drawObject(inViewScene.getObjectByIndex(i));
    refresh();
}
