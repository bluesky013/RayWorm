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

class Bounding {
public:
    Bounding() : pMin(glm::vec3(0, 0, 0)), pMax(glm::vec3(0, 0, 0)) {}

    Bounding(const glm::vec3& min, const glm::vec3& max) : pMin(min), pMax(max) {}

    bool overlaps(const Bounding& rhs) const;

    bool isInside(const glm::vec3& pt) const;

    void update(const glm::vec3& min, const glm::vec3& max)
    {
        pMin = min;
        pMax = max;
    }

private:
    glm::vec3 pMin;
    glm::vec3 pMax;
};

class Shape {
public:
    virtual bool calculateRayIntersection(const Ray& ray, SurfaceIntersection& intersection) = 0;

    virtual Bounding getLocalBounding() = 0;

    virtual Bounding getWorldBounding() = 0;
};

class Triangle : public Shape {
public:
    Triangle(const glm::vec3& p0t, const glm::vec3& p1t, const glm::vec3& p2t);

    bool calculateRayIntersection(const Ray& ray, SurfaceIntersection& intersection) override;

protected:
    Bounding getLocalBounding() override {
        return Bounding();
    }

    Bounding getWorldBounding() override {
        return Bounding();
    }

private:
    glm::vec3 p0;
    glm::vec3 p1;
    glm::vec3 p2;
    glm::vec3 normal;
};

class Sphere : public Shape  {
public:
    Sphere(const glm::mat4& worldTrans, Real r);

    bool calculateRayIntersection(const Ray& ray, SurfaceIntersection& intersection) override;

protected:
    Bounding getLocalBounding() override;

    Bounding getWorldBounding() override;

private:
    glm::mat4 transform;
    Real radius;
};

class Plane : public Shape {
public:
    Plane(const glm::mat4& worldTrans, const glm::vec3& nm, Real ext = 1.0f);

    bool calculateRayIntersection(const Ray& ray, SurfaceIntersection& intersection) override;

protected:
    Bounding getLocalBounding() override {
        return Bounding();
    }

    Bounding getWorldBounding() override {
        return Bounding();
    }

private:
    glm::mat4 transform;
    glm::vec3 normal;
    Real extent;
};


}
}


#endif