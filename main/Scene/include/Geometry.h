#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <glm/glm.hpp>
#include <vector>

namespace RayWorm {
namespace Scene {

struct Geometry {
    std::vector<glm::vec3> positions;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> uv0;
    std::vector<glm::vec2> uv1;
    std::vector<uint32_t> indices;
};

}
}
#endif