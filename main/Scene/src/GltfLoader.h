

#ifndef RAY_GLTF_LOADER_H
#define RAY_GLTF_LOADER_H

#include <RayLoader.h>
#include <memory>

namespace tinygltf {
class Model;
}

namespace RayWorm {
namespace Scene {

class GltfLoader : public Loader {
public:
    GltfLoader() {}
    ~GltfLoader() {}

    bool load(const std::string& url, const std::string& ext) override;

    bool instantiateMesh(const std::string& name, Mesh& mesh) override;

private:
    std::unique_ptr<tinygltf::Model> model;
};


}
}


#endif