#ifndef RAY_GEOMETRY_H
#define RAY_GEOMETRY_H

#include <RayBasic.h>
#include <glm/glm.hpp>
#include <vector>
#include <RayShape.h>
#include <RaySingleton.h>

namespace RayWorm {
namespace Scene {
class PrimitiveBuilder;

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
        WEIGHT
    };

    /**
     * add attributes of primitive.
     */
    Primitive& setAttribute(AttributeType type, char* data, size_t size);

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
    std::vector<BufferPtr> attributes;
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