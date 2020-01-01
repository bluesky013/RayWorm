#ifndef RAY_GEOMETRY_H
#define RAY_GEOMETRY_H

#include <RayBasic.h>
#include <glm/glm.hpp>
#include <vector>
#include <RayShape.h>
#include <RaySingleton.h>
#include <RayBuffer.h>

namespace RayWorm {
namespace Scene {
class PrimitiveBuilder;
struct BufferAccessor;

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
    Primitive& buildBoundingBox();

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
    Box boundingBox;
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