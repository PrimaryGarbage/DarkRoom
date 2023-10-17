#include "logger.hpp"
#include <iostream>
#include "time.hpp"

namespace prim
{
    void Logger::logInfo(std::string message)
    {
        std::cout << Time::getTimestamp() << " [INFO]" << message;
    }
    
    void Logger::logWarning(std::string message)
    {
        std::cout << Time::getTimestamp() << " [WARNING]" << message;
    }
    
    void Logger::logError(std::string message)
    {
        std::cout << Time::getTimestamp() << " [ERROR]" << message;
    }
}