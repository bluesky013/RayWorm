#ifndef WORM_CAMERA_H
#define WORM_CAMERA_H

#include <vector>
#include <RayNode.h>
#include <RayBasic.h>

namespace Worm {
namespace Scene {

class Camera : public Node {
public:
    enum Mode {
        PERSPECITVE,
        ORTHOGONAL
    };

    Camera(const std::string& name) : Node(name) {}
    ~Camera() {}

    void setMode(Mode m) { mode = m; }

    void updateViewport(Real w, Real h) { width = w; height = h; }

    glm::mat4 getProjectMatrix() const;

    glm::mat4 getViewMatrix() const;

private:
    Real fov = 60.f;
    Real near = 0.1f;
    Real far = 100.f;
    Real aspect = 3.f / 4.f;
    Real width = 1.f;
    Real height = 1.f;
    Mode mode = PERSPECITVE;
};

}
}


#endif