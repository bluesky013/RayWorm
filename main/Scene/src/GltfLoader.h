

#ifndef GLTF_LOADER_H
#define GLTF_LOADER_H

#include <Loader.h>

namespace RayWorm {
namespace Scene {

class GltfLoader : public Loader {
public:
    GltfLoader() {}
    ~GltfLoader() {}

    bool load(const std::string& url, const std::string& ext) override;
};


}
}


#endif