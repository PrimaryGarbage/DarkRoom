#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <string>

namespace prim
{
    class Logger
    {
    public:
        static void logInfo(std::string message);
        static void logWarning(std::string message);
        static void logError(std::string message);
    };
}


#endif // __LOGGER_HPP__