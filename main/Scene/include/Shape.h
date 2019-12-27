#ifndef SHAPE_H
#define SHAPE_H

#include <glm/glm.hpp>
#include <Basic.h>

namespace RayWorm {
namespace Scene {

struct Box {
    glm::vec3 pMin;
    glm::vec3 pMax;

    bool overlaps(const Box& rhs) const;

    bool isInside(const glm::vec3& pt) const;
};

struct Sphere {
    glm::vec3 center;
    Real radius;
};


}
}


#endif