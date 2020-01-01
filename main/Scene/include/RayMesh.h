#ifndef RAY_MESH_H
#define RAY_MESH_H

#include <RayBasic.h>
#include <RayNode.h>
#include <vector>

namespace RayWorm {
namespace Scene {

class Mesh : public Node {
public:
    Mesh(const std::string& name) : Node(name) {}
    ~Mesh() {}

    void addPrimitive(PrimitivePtr primitive);

private:
    std::vector<PrimitivePtr> primitives;
};

}
}


#endif