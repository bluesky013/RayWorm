
#include <GltfLoader.h>
#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <tiny_gltf.h>
#include <algorithm>

#include <RayMesh.h>
#include <RayPrimitive.h>
#include <RayBuffer.h>
#include <RayDebug.h>

#include <iostream>

using namespace tinygltf;

namespace RayWorm {
namespace Scene {
namespace {
const std::string TAG = "[GltfLoader]";

BufferAccessor::CompType getComponentType(int compType)
{
    switch (compType) {
    case TINYGLTF_COMPONENT_TYPE_BYTE:
        return BufferAccessor::CompType::BYTE;
    case TINYGLTF_COMPONENT_TYPE_UNSIGNED_BYTE:
        return BufferAccessor::CompType::UBYTE;
    case TINYGLTF_COMPONENT_TYPE_SHORT:
        return BufferAccessor::CompType::SHORT;
    case TINYGLTF_COMPONENT_TYPE_UNSIGNED_SHORT:
        return BufferAccessor::CompType::USHORT;
    case TINYGLTF_COMPONENT_TYPE_INT:
        return BufferAccessor::CompType::INT;
    case TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT:
        return BufferAccessor::CompType::UINT;
    case TINYGLTF_COMPONENT_TYPE_FLOAT:
        return BufferAccessor::CompType::FLOAT;
    case TINYGLTF_COMPONENT_TYPE_DOUBLE:
        return BufferAccessor::CompType::DOUBLE;
    default:
        return BufferAccessor::CompType::BYTE;
    };
}

BufferAccessor::DataType getDataType(int dataType)
{
    switch (dataType) {
    case TINYGLTF_TYPE_SCALAR:
        return BufferAccessor::DataType::SCALAR;
    case TINYGLTF_TYPE_VEC2:
        return BufferAccessor::DataType::VEC2;
    case TINYGLTF_TYPE_VEC3:
        return BufferAccessor::DataType::VEC3;
    case TINYGLTF_TYPE_VEC4:
        return BufferAccessor::DataType::VEC4;
    case TINYGLTF_TYPE_MAT2:
        return BufferAccessor::DataType::MAT2;
    case TINYGLTF_TYPE_MAT3:
        return BufferAccessor::DataType::MAT3;
    case TINYGLTF_TYPE_MAT4:
        return BufferAccessor::DataType::MAT4;
    default:
        return BufferAccessor::DataType::SCALAR;
    }
}

Primitive::AttributeType getAttributeType(const std::string& name)
{
    if (name == "POSITION") {
        return Primitive::AttributeType::POSITION;
    } else if (name == "NORMAL") {
        return Primitive::AttributeType::NORMAL;
    } else if (name == "TANGENT") {
        return Primitive::AttributeType::TANGENT;
    } else if (name == "TEXCOORD_0") {
        return Primitive::AttributeType::UV0;      
    } else if (name == "TEXCOORD_1") {
        return Primitive::AttributeType::UV1;
    } else if (name == "COLOR_0") {
        return Primitive::AttributeType::COLOR;
    } else if (name == "JOINTS_0") {
        return Primitive::AttributeType::JOINTS;
    } else if (name == "WEIGHTS_0") {
        return Primitive::AttributeType::WEIGHT;
    }

    return Primitive::AttributeType::POSITION;
}

BufferAccessor createBuffer(tinygltf::Model& model, tinygltf::Accessor& accessor)
{
    auto& bufferview = model.bufferViews[accessor.bufferView];
    const uint8_t* dataAddress = model.buffers[bufferview.buffer].data.data() +
        accessor.byteOffset + bufferview.byteOffset;

    BufferPtr buffer = BufferBuilder::getSingleton().CreateBuffer(bufferview.byteLength);
    buffer->setData(dataAddress);
    return BufferAccessor { buffer, getComponentType(accessor.componentType),
        getDataType(accessor.count), accessor.count };
}

}

bool GltfLoader::load(const std::string& url, const std::string& ext)
{
    TinyGLTF gltf;
    std::string err;
    std::string warn;

    bool result = false;
    model = std::make_unique<Model>();

    if (ext == "gltf") {
        result = gltf.LoadASCIIFromFile(model.get(), &err, &warn, url);
    } else if (ext == "glb") {
        result = gltf.LoadBinaryFromFile(model.get(), &err, &warn, url);
    }

    return result;
}

bool GltfLoader::instantiateMesh(const std::string& name, Mesh& mesh)
{
    if (!model) {
        return false;
    }

    auto iter = std::find_if(model->nodes.begin(), model->nodes.end(), [&name](const tinygltf::Node& node) -> bool {
        return node.name == name;
    });

    mesh.setName(iter->name);
    if (iter->translation.size() != 0) {
        mesh.setPosition(glm::vec3(iter->translation[0], iter->translation[1], iter->translation[2]));
    }

    if (iter->scale.size() != 0) {
        mesh.setScale(glm::vec3(iter->scale[0], iter->scale[1], iter->scale[2]));
    }

    if (iter->rotation.size() != 0) {
        mesh.setOrientation(glm::quat(iter->scale[3], iter->scale[0], iter->scale[1], iter->scale[2]));
    }

    tinygltf::Mesh& ms = model->meshes[iter->mesh];
    std::vector<tinygltf::Primitive>& attributes = ms.primitives;
    for (auto attr : attributes) {
        PrimitivePtr prim = PrimitiveBuilder::getSingleton().CreatePrimitive();
        for (auto acc : attr.attributes) {
            auto& accessor = model->accessors[acc.second];

            /* add attribute */
            prim->setAttribute(getAttributeType(acc.first), createBuffer(*model, accessor));
        }

        auto& accessor = model->accessors[attr.indices];
        prim->setIndices(createBuffer(*model, accessor))
            .buildBoundingBox();
    }

    return true;
}


}
}