

#include <Shape.h>


namespace RayWorm {
namespace Scene {

bool Box::overlaps(const Box& rhs) const
{
    bool x = (pMax.x >= rhs.pMin.x) && (pMax.x <= rhs.pMax.x);
    bool y = (pMax.y >= rhs.pMin.y) && (pMax.x <= rhs.pMax.y);
    bool z = (pMax.z >= rhs.pMin.z) && (pMax.x <= rhs.pMax.z);
    return x && y && z;
}

bool Box::isInside(const glm::vec3& pt) const
{
    bool x = pt.x >= pMin.x && pt.x <= pMax.x;
    bool y = pt.y >= pMin.y && pt.y <= pMax.y;
    bool z = pt.z >= pMin.z && pt.z <= pMax.z;
    return x && y && z;
}


}
}