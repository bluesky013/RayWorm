#ifndef Worm_LOG_H
#define Worm_LOG_H

#include <string>

namespace Worm {
namespace Common {

class LogManager {
public:
    enum class Level : uint8_t {
        INFO,
        WARNING,
        ERROR
    };

    static void logPrint(LogManager::Level level, const std::string& tag, const std::string& info);
};

#define LOG_PRINT_INFO(tag, ...) \
{\
    char str[100];\
    sprintf(str, __VA_ARGS__);\
    Common::LogManager::logPrint(Common::LogManager::Level::INFO, tag, str);\
}

}
}



#endif