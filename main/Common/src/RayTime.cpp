

#include <RayTime.h>
#include <ctime>

namespace Worm {
namespace Common {

std::string Time::getCurrentTime()
{
    time_t now = time(0);
    return std::ctime(&now);
}


}
}