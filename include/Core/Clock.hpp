#pragma once
#include <chrono>

class Clock{
public:
    Clock();
    
    void update();

    bool isFrame();
    bool isTick();
    
    static constexpr double framesPerSecond = 30;
    static constexpr double ticksPerSecond  = 20;

    static constexpr double deltaTime       = 1.0/ticksPerSecond;
    static constexpr double deltaFrame      = 1.0/framesPerSecond;
private:
    double                                elapsed;
    std::chrono::steady_clock::time_point currentTime;
    std::chrono::steady_clock::time_point lastTick;
    std::chrono::steady_clock::time_point lastFrame;
};
