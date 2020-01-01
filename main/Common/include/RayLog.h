#ifndef RAYWORM_LOG_H
#define RAYWORM_LOG_H

#include <string>

namespace RayWorm {
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

}
}



#endif