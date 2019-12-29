#ifndef OBJECT_H
#define OBJECT_H

#include <Node.h>
#include <Primitive.h>

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