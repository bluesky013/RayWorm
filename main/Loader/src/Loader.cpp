

#include <Loader.h>
#include <GltfLoader.h>
#include <tiny_gltf.h>

namespace RayWorm {
namespace Loader {

Loader* Loader::loadAsset(const std::string& url)
{
    auto idx = url.find_last_of(".");
    if (idx == std::string::npos) {
        return nullptr;
    }
    std::string ext = url.substr(idx + 1);
    Loader* loader = nullptr;
    if (ext == "gltf" || ext == "glb") {
        loader = new GltfLoader();
    }

    return loader;
}


}
}