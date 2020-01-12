

#include <RayShape.h>
#include <RayLog.h>

namespace Worm {
namespace Shape {
namespace {
const std::string TAG = "[Shape]";
uint32_t maxDimension(const glm::vec3 &v)
{
    return (v.x > v.y) ? ((v.x > v.z) ? 0 : 2) :
        ((v.y > v.z) ? 1 : 2);
}

glm::vec3 permute(const glm::vec3& v, uint32_t kx, uint32_t ky, uint32_t kz)
{
    return glm::vec3(v[kx], v[ky], v[kz]);
}
}

Ray::Ray(const glm::vec3& o, const glm::vec3& d) : origin(o), direction(d)
{
    kz = maxDimension(glm::abs(direction));
    kx = kz + 1; if (kx == 3) kx = 0;
    ky = kx + 1; if (ky == 3) ky = 0;
    glm::vec3 p = permute(direction, kx, ky, kz);
    sx = -p.x / p.z;
    sy = -p.y / p.z;
    sz = 1 / p.z;
}

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

bool Triangle::calculateRayIntersection(const Ray& ray, SurfaceIntersection& intersection)
{
    glm::vec3 p0t = p0 - ray.origin;
    glm::vec3 p1t = p1 - ray.origin;
    glm::vec3 p2t = p2 - ray.origin;

    p0t = permute(p0t, ray.kx, ray.ky, ray.kz);
    p1t = permute(p1t, ray.kx, ray.ky, ray.kz);
    p2t = permute(p2t, ray.kx, ray.ky, ray.kz);

    p0t.x += ray.sx * p0t.z;
    p0t.y += ray.sy * p0t.z;
    p1t.x += ray.sx * p1t.z;
    p1t.y += ray.sy * p1t.z;
    p2t.x += ray.sx * p2t.z;
    p2t.y += ray.sy * p2t.z;

    Real e0 = p1t.x * p2t.y - p1t.y * p2t.x;
    Real e1 = p2t.x * p0t.y - p2t.y * p0t.x;
    Real e2 = p0t.x * p1t.y - p0t.y * p1t.x;

    if ((e0 < 0 || e1 < 0 || e2 < 0) && (e0 > 0 || e1 > 0 || e2 > 0)) {
        return false;
    }

    float det = e0 + e1 + e2;
    if (det == 0) {
        return false;
    }

    p0t.z *= ray.sz;
    p1t.z *= ray.sz;
    p2t.z *= ray.sz;

    Real tScale = e0 * p0t.z + e1 * p1t.z + e2 * p2t.z;
    if (det < 0 && (tScale >= 0 || tScale < ray.tMax *  det)) {
        return false;
    } else if (det > 0 && (tScale <= 0 || tScale > ray.tMax *  det)) {
        return false;
    }

    Real invDet = 1 / det;
    Real b0 = e0 * invDet;
    Real b1 = e1 * invDet;
    Real b2 = e2 * invDet;
    Real t = tScale * invDet;

    intersection.hitPoint = b0 * p0 + b1 * p1 + b2 * p2;
    intersection.uv = b0 * uv0 + b1 * uv1 + b2 * uv2;

    return true;
}

}
}