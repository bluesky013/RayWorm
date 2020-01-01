
#include <GltfLoader.h>
#include <tiny_gltf.h>
#include <algorithm>

#include <RayMesh.h>
#include <RayPrimitive.h>
#include <RayBuffer.h>
#include <RayDebug.h>

using namespace tinygltf;

namespace RayWorm {
namespace Scene {
namespace {
const std::string TAG = "[GltfLoader]";

Primitive::AttributeType FromTinyGLtf(const std::string& name)
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
}

BufferPtr FromTinyGLtf(const tinygltf::Model& model, int access)
{
    auto& accessor = model.accessors[access];
    //BufferBuilder::getSingleton().CreateBuffer()


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
    auto& attributes = ms.primitives;
    for (auto attribute : attributes) {

    }

    return true;
}


}
}