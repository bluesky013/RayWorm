#ifndef SHAPE_H
#define SHAPE_H

#include <glm/glm.hpp>
#include <RayBasic.h>

namespace Worm {
namespace Shape {

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
    glm::vec2 uv;
};

struct Shape {
    virtual bool calculateRayIntersection(const Ray& ray, SurfaceIntersection& intersection) = 0;
};

struct Box : public Shape {
    glm::vec3 pMin;
    glm::vec3 pMax;

    Box() : pMin(glm::vec3(0, 0, 0)), pMax(glm::vec3(0, 0, 0)) {}

    Box(const glm::vec3& min, const glm::vec3& max) : pMin(min), pMax(max) {}

    bool overlaps(const Box& rhs) const;

    bool isInside(const glm::vec3& pt) const;

    bool calculateRayIntersection(const Ray& ray, SurfaceIntersection& intersection) override
    {
        return false;
    }
};

struct Triangle : public Shape {
    glm::vec3 p0;
    glm::vec3 p1;
    glm::vec3 p2;

    glm::vec2 uv0 = glm::vec2(0, 0);
    glm::vec2 uv1 = glm::vec2(1, 0);
    glm::vec2 uv2 = glm::vec2(1, 1);

    Triangle(const glm::vec3& p0t, const glm::vec3& p1t, const glm::vec3& p2t) : p0(p0t), p1(p1t), p2(p2t) {}

    bool calculateRayIntersection(const Ray& ray, SurfaceIntersection& intersection);
};

struct Sphere : public Shape  {
    glm::vec3 center;
    Real radius;

    bool calculateRayIntersection(const Ray& ray, SurfaceIntersection& intersection) override
    {
        return false;
    }
};


}
}


#endif