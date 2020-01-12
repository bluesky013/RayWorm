#include <RayMesh.h>


namespace Worm {
namespace Scene {
using namespace Asset;

void Mesh::addPrimitive(PrimitivePtr primitive)
{
    primitives.emplace_back(primitive);
}

}
}