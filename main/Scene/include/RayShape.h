#ifndef SHAPE_H
#define SHAPE_H

#include <glm/glm.hpp>
#include <RayBasic.h>

namespace RayWorm {
namespace Scene {

struct Ray {
    glm::vec3 origin;
    glm::vec3 direction;
    glm::vec3 shear;
    uint32_t kx;
    uint32_t ky;
    uint32_t kz;
    Real sx;
    Real sy;
    Real sz;
    Real tMax = 1000;
    Ray(const glm::vec3& o, const glm::vec3& d);
};

struct SurfaceIntersection {
    glm::vec3 hitPoint;
    glm::vec3 normal;
};

struct Box {
    glm::vec3 pMin;
    glm::vec3 pMax;

    bool overlaps(const Box& rhs) const;

    bool isInside(const glm::vec3& pt) const;
};

struct Triangle {
    glm::vec3 p0;
    glm::vec3 p1;
    glm::vec3 p2;

    bool calculateRayIntersection(const Ray& ray, SurfaceIntersection& intersection);
};

struct Sphere {
    glm::vec3 center;
    Real radius;
};


}
}


#endif