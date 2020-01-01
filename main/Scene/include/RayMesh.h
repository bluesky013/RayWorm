#ifndef RAY_MESH_H
#define RAY_MESH_H

#include <RayNode.h>
#include <RayPrimitive.h>

namespace RayWorm {
namespace Scene {

class Mesh : public Node {
public:
    Mesh(const std::string& name) : Node(name) {}
    ~Mesh() {}

private:
    
};

}
}


#endif