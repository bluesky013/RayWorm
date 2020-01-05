
#include <RayPrimitive.h>
#include <RayDebug.h>
#include <algorithm>

namespace RayWorm {
namespace Scene {
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
                    boundingBox.pMin = pt;
                    boundingBox.pMax = pt;
                    first = false;
                    continue;
                }

                boundingBox.pMin.x = std::min(boundingBox.pMin.x, pt.x);
                boundingBox.pMin.y = std::min(boundingBox.pMin.y, pt.y);
                boundingBox.pMin.z = std::min(boundingBox.pMin.z, pt.z);

                boundingBox.pMax.x = std::max(boundingBox.pMax.x, pt.x);
                boundingBox.pMax.y = std::max(boundingBox.pMax.y, pt.y);
                boundingBox.pMax.z = std::max(boundingBox.pMax.z, pt.z);
            }
        }
    }
    return *this;
}

bool Primitive::rayCast(const Ray& ray, SurfaceIntersection& intersect) const
{
    return true;
}

PrimitivePtr PrimitiveBuilder::CreatePrimitive()
{
    primitiveCache.emplace_back(PrimitivePtr(new Primitive(*this)));
    return primitiveCache.back();
}

}
}