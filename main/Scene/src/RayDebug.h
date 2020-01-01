
#ifndef RAY_DEBUG_H
#define RAY_DEBUG_H

#include <RayLog.h>
#include <string>

namespace RayWorm {
namespace Scene {


#define LOG_PRINT_INFO(tag, ...) \
{\
    char str[100];\
    sprintf(str, __VA_ARGS__);\
    Common::LogManager::logPrint(Common::LogManager::Level::INFO, tag, str);\
}
}
}

#endif