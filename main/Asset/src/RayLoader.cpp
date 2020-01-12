

#include <RayLoader.h>
#include <GltfLoader.h>
#include <tiny_gltf.h>
#include <RayLog.h>

namespace Worm {
namespace Asset {
namespace {

const std::string TAG = "Loader";

}

Loader* Loader::loadAsset(const std::string& url)
{
    LOG_PRINT_INFO(TAG, "load asset url:%s", url.c_str());
    auto idx = url.find_last_of(".");
    if (idx == std::string::npos) {
        return nullptr;
    }
    std::string ext = url.substr(idx + 1);
    Loader* loader = nullptr;
    if (ext == "gltf" || ext == "glb") {
        loader = new GltfLoader();
        if (loader) {
            loader->load(url, ext);
        }
    }

    LOG_PRINT_INFO(TAG, "load asset result:%d", loader != nullptr);

    return loader;
}


}
}