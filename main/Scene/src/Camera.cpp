

#include <Camera.h>


namespace RayWorm {
namespace Scene {

glm::mat4 Camera::getProjectMatrix() const
{
    if (mode == PERSPECITVE) {
        return glm::perspective(fov, aspect, near, far);
    } else {
        return glm::ortho(-width / 2.f, width / 2.f, -height / 2.f, height / 2.f);
    }
}

glm::mat4 Camera::getViewMatrix() const
{
    return glm::inverse(getTransform());
}


}
}