
#include <RayPrimitive.h>
#include <RayLog.h>
#include <algorithm>

namespace Worm {
namespace Asset {
namespace {
const std::string TAG = "[Primitive]";

}

Primitive::Primitive(PrimitiveBuilder& pb) : builder(pb)
{
    attributes.resize(AttributeType::MAX);
}

Primitive& Primitive::setAttribute(AttributeType type, const BufferAccessor& accessor)
{
    attributes[static_cast<size_t>(type)] = std::make_unique<BufferAccessor>(accessor);
    return *this;
}

Primitive& Primitive::setIndices(const BufferAccessor& accessor)
{
    indices = std::make_unique<BufferAccessor>(accessor);
    return *this;
}

Primitive& Primitive::buildPrimitive()
{
    if (attributes[static_cast<size_t>(AttributeType::POSITION)]) {
        BufferAccessor* accessor = attributes[static_cast<size_t>(AttributeType::POSITION)].get();
        if (accessor->compType == BufferAccessor::CompType::FLOAT) {
            std::vector<float> vtx(accessor->buffer->getBufferSize() / sizeof(float));
            memcpy(vtx.data(), accessor->buffer->getData(), accessor->buffer->getBufferSize());

            bool first = true;
            for (size_t i = 0; i < vtx.size();i+=accessor->count) {
                glm::vec3 pt = glm::vec3(vtx[i], vtx[i + 1], vtx[i + 2]);
                if (first) {
                    first = false;
                    continue;
                }
            }
        }
    }
    return *this;
}

PrimitivePtr PrimitiveBuilder::CreatePrimitive()
{
    primitiveCache.emplace_back(PrimitivePtr(new Primitive(*this)));
    return primitiveCache.back();
}

}
}