
#ifndef RAY_DEBUG_H
#define RAY_DEBUG_H

#include <RayLog.h>

namespace RayWorm {
namespace Scene {


#define logPrintInfo(tag, data) \
    Common::LogManager::logPrint(Common::LogManager::Level::INFO, tag, data)

}
}

#endif