#include <RayMesh.h>


namespace RayWorm {
namespace Scene {

void Mesh::addPrimitive(PrimitivePtr primitive)
{
    primitives.emplace_back(primitive);
}

}
}