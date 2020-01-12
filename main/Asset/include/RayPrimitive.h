#ifndef WORM_GEOMETRY_H
#define WORM_GEOMETRY_H

#include <glm/glm.hpp>
#include <vector>
#include <RaySingleton.h>
#include <RayBuffer.h>

namespace Worm {
namespace Asset {
class PrimitiveBuilder;
struct BufferAccessor;
class Primitive;
using PrimitivePtr = std::shared_ptr<Primitive>;

class Primitive {
public:
    enum AttributeType : uint8_t {
        POSITION = 0,
        NORMAL,
        TANGENT,
        UV0,
        UV1,
        COLOR,
        JOINTS,
        WEIGHT,
        MAX
    };

    /**
     * add attributes of primitive.
     */
    Primitive& setAttribute(AttributeType type, const BufferAccessor& accessor);

    /**
     * set indices of the buffers.
     */
    Primitive& setIndices(const BufferAccessor& accessor);

    /**
     * If set bounding box, primitive will not update bounding box automatically.
    */
    Primitive& buildPrimitive();

protected:
    Primitive(PrimitiveBuilder& pb);
    ~Primitive() {}

    friend struct std::default_delete<Primitive>;
    friend class PrimitiveBuilder;
private:
    using BufferAccessorPtr = std::unique_ptr<BufferAccessor>;

    PrimitiveBuilder& builder;
    std::vector<BufferAccessorPtr> attributes;
    BufferAccessorPtr indices;
};

class PrimitiveBuilder : public Common::Singleton<PrimitiveBuilder> {
public:
     PrimitivePtr CreatePrimitive();
private:
     std::vector<PrimitivePtr> primitiveCache;
};

}
}
#endif