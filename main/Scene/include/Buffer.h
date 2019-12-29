#ifndef BUFFER_H
#define BUFFER_H

#include <Basic.h>
#include <vector>
#include <memory>
#include <Singleton.h>

namespace RayWorm {
namespace Scene {
class BufferBuilder;

using Memory = std::vector<char>;

class Buffer {
public:
    const char* getData() const { return data.data(); }

    void setData(char* dt, size_t size);

protected:
    Buffer(BufferBuilder& fct, size_t size);
    ~Buffer() {};
    friend struct std::default_delete<Buffer>;
    friend class BufferBuilder;
private:
    BufferBuilder& builder;
    Memory data;
};

class BufferBuilder : public Common::Singleton<BufferBuilder> {
public:
    BufferBuilder() {}
    ~BufferBuilder() {}

    BufferPtr CreateBuffer(size_t size);

private:
    std::vector<BufferPtr> bufferCache;
};


}
}


#endif