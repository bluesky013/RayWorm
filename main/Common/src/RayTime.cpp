

#include <RayTime.h>

#include <sstream>
#include <ctime>

namespace RayWorm {
namespace Common {

std::string Time::getCurrentTime()
{
    time_t now = time(0);
    std::stringstream ss(std::ctime(&now));
    return ss.str().c_str();
}


}
}