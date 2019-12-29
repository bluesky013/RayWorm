#include <Buffer.h>
#include <exception>

namespace RayWorm {
namespace Scene {

Buffer::Buffer(BufferBuilder& fct, size_t size) : builder(fct)
{
    data.resize(size);
}

void Buffer::setData(char* dt, size_t size)
{
    if (size > data.size()) {
        throw std::invalid_argument("buffer data size greater than created size");
        return;
    }

    memcpy(data.data(), dt, size);
}

BufferPtr BufferBuilder::CreateBuffer(size_t size)
{
    bufferCache.emplace_back(BufferPtr(new Buffer(*this, size)));
    return bufferCache.back();
}


}
}