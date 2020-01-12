#ifndef WORM_BUFFER_H
#define WORM_BUFFER_H

#include <RayBasic.h>
#include <vector>
#include <memory>
#include <RaySingleton.h>

namespace Worm {
namespace Asset {
class BufferBuilder;
class Buffer;
using BufferPtr = std::shared_ptr<Buffer>;
using Memory = std::vector<uint8_t>;

class Buffer {
public:
    void setData(const uint8_t* dt);

    const uint8_t* getData() const { return data.data(); }

    size_t getBufferSize() const { return data.size(); }

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

struct BufferAccessor {
    enum class CompType : uint8_t {
        BYTE   = 0,
        UBYTE  = 1,
        SHORT  = 2,
        USHORT = 3,
        INT    = 4,
        UINT   = 5,
        FLOAT  = 6,
        DOUBLE = 7
    };

    enum class DataType : uint8_t {
        SCALAR = 0,
        VEC2   = 1,
        VEC3   = 2,
        VEC4   = 3,
        MAT2   = 4,
        MAT3   = 5,
        MAT4   = 6
    };
    BufferPtr buffer;
    CompType compType;
    DataType dataType;
    size_t count;
    
    static uint8_t getDataElementsCount(DataType type);
};


}
}


#endif