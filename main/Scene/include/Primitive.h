#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <Basic.h>
#include <glm/glm.hpp>
#include <vector>
#include <Shape.h>
#include <Singleton.h>

namespace RayWorm {
namespace Scene {
class PrimitiveBuilder;

class Primitive {
public:
    /**
     * add attributes of primitive.
     */
    Primitive& setAttribute(char* data, size_t size);

    /**
     * set indices of the buffers.
     */
    Primitive& setIndices(char* data, size_t size);

    /**
     * If set bounding box, primitive will not update bounding box automatically.
    */
    Primitive& setBounding(const Box& box);

    void update();

protected:
    Primitive(PrimitiveBuilder& pb) : builder(pb) {}
    ~Primitive() {}

    friend struct std::default_delete<Primitive>;
    friend class PrimitiveBuilder;
private:
    PrimitiveBuilder& builder;
    std::vector<BufferPtr> buffers;
    std::vector<uint32_t> indices;
    Box bounding;
};

class PrimitiveBuilder : public Common::Singleton<PrimitiveBuilder> {
public:
     BufferPtr CreateBuffer(size_t size);
private:
     std::vector<PrimitivePtr> primitiveCache;
};

}
}
#endif