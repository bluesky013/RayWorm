
#include <RayPrimitive.h>

namespace RayWorm {
namespace Scene {

Primitive& Primitive::setAttribute(AttributeType type, char* data, size_t size)
{
    return *this;
}

Primitive& Primitive::setIndices(char* data, size_t size)
{
    return *this;
}

Primitive& Primitive::setBounding(const Box& box)
{
    return *this;
}

void Primitive::update()
{

}


}
}