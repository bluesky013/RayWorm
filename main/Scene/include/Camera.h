#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <vector>

namespace RayWorm {
namespace Scene {

class Camera {
public:
    Camera() {}
    ~Camera() {}

    void lookAt(const glm::vec3& target);

private:
    float fov = 60.f;
    float near = 0.1f;
    float far = 100.f;
    float aspect = 3.f / 4.f;
};

}
}


#endif