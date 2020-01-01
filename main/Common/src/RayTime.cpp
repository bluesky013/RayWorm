

#include <RayTime.h>
#include <ctime>

namespace RayWorm {
namespace Common {

std::string Time::getCurrentTime()
{
    time_t now = time(0);
    return std::ctime(&now);
}


}
}