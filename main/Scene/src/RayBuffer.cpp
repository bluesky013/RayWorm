#include <RayBuffer.h>
#include <exception>
#include <RayLog.h>

namespace RayWorm {
namespace Scene {

Buffer::Buffer(BufferBuilder& fct, size_t size) : builder(fct)
{
    data.resize(size);
}

void Buffer::setData(const uint8_t* dt)
{
    memcpy(data.data(), dt, data.size());
}

BufferPtr BufferBuilder::CreateBuffer(size_t size)
{
    bufferCache.emplace_back(BufferPtr(new Buffer(*this, size)));
    return bufferCache.back();
}

uint8_t BufferAccessor::getDataElementsCount(DataType type)
{
    switch (type) {
    case DataType::SCALAR:
        return 1;
    case DataType::VEC2:
        return 2;
    case DataType::VEC3:
        return 3;
    case DataType::VEC4:
    case DataType::MAT2:
        return 4;
    case DataType::MAT3:
        return 9;
    case DataType::MAT4:
        return 16;
    default:
        return 1;
    }
}


}
}