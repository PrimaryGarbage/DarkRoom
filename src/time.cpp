#include "time.hpp"
#include <ctime>
#include <sstream>

namespace prim
{
    std::string Time::getTimestamp()
    {
        std::time_t ticks = std::time(0);
        std::tm* time = std::localtime(&ticks);
        std::stringstream sstream;
        sstream << time->tm_hour << ':' << time->tm_min << ':' << time->tm_sec;
        return sstream.str();
    }
}