#ifndef WORM_MESH_H
#define WORM_MESH_H

#include <RayBasic.h>
#include <RayNode.h>
#include <RayPrimitive.h>
#include <vector>

namespace Worm {
namespace Scene {

class Mesh : public Node {
public:
    Mesh(const std::string& name) : Node(name) {}
    ~Mesh() {}

    void addPrimitive(Asset::PrimitivePtr primitive);

private:
    std::vector<Asset::PrimitivePtr> primitives;
};

}
}


#endif