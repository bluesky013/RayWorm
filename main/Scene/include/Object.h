#ifndef OBJECT_H
#define OBJECT_H

#include <Node.h>
#include <Geometry.h>

namespace RayWorm {
namespace Scene {

class Object : public Node {
public:
    Object(const std::string& name) : Node(name) {}
    ~Object() {}

private:
    
};

}
}


#endif