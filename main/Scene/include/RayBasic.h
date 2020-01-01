

#ifndef RAY_BASIC_H
#define RAY_BASIC_H

#include <vector>

namespace RayWorm {
namespace Scene {

#ifdef DOUBLE_PRECISION
#define Real double
#else
#define Real float
#endif

class Buffer;
using BufferPtr = std::shared_ptr<Buffer>;

class Primitive;
using PrimitivePtr = std::shared_ptr<Primitive>;

}
}

#endif