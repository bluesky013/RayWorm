
#include <RayLog.h>

#include <iostream>

#include <RayTime.h>

namespace RayWorm {
namespace Common {
namespace {

std::string levelToStr(const LogManager::Level& level)
{
    if (level == LogManager::Level::WARNING) {
        return "Warning";
    }

    if (level == LogManager::Level::ERROR) {
        return "Error";
    }

    return "Info";
}

}

void LogManager::logPrint(LogManager::Level level, const std::string& tag, const std::string& info)
{
    std::string output = Time::getCurrentTime();
    output += tag + " ";
    output += levelToStr(level) + ": ";
    output += info;
    std::cout << output.c_str() << std::endl;
}


}
}