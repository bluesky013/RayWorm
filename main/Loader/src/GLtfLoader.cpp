
#include <GltfLoader.h>
#include <tiny_gltf.h>

using namespace tinygltf;

namespace RayWorm {
namespace Loader {


bool GltfLoader::load(const std::string& url, const std::string& ext)
{
    TinyGLTF gltf;
    Model model;
    std::string err;
    std::string warn;

    bool result = false;

    if (ext == "gltf") {
        result = gltf.LoadASCIIFromFile(&model, &err, &warn, url);
    } else if (ext == "glb") {
        result = gltf.LoadBinaryFromFile(&model, &err, &warn, url);
    }

    return result;
}


}
}