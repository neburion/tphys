#include "core/Clock.hpp"
#include <chrono>

Clock::Clock():
    currentTime(std::chrono::steady_clock::now()),
    lastTick(std::chrono::steady_clock::now()),
    lastFrame(std::chrono::steady_clock::now())
{}

void Clock::update(){
    currentTime = std::chrono::steady_clock::now();
}

bool Clock::isTick(){
    std::chrono::duration<double> elapsed = currentTime - lastTick;
    if(elapsed.count() >= deltaTime){
        lastTick = currentTime;
        return true;
    }
    return false;
}

bool Clock::isFrame(){
    std::chrono::duration<double> elapsed = currentTime - lastFrame;
    if(elapsed.count() >= deltaFrame){
        lastFrame = currentTime;
        return true;
    }
    return false;
}
