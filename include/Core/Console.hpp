#pragma once
#include <string>

class Console{
public:
    static void        log               (const std::string &msg);
    static std::string &getLine          (uint index);
    std::string        &getOffsetLastLine(uint offset);

    static const int MAX_LINES = 5;
private:
    static std::string lines[MAX_LINES];
    static int         currentLine;
};
