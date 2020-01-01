

#ifndef RAY_LOADER_H
#define RAY_LOADER_H

#include <string>

namespace RayWorm {
namespace Scene {
class Node;
class Mesh;

class Loader {
public:
    static Loader* loadAsset(const std::string& url);

    virtual bool load(const std::string& url, const std::string& ext) = 0;

    virtual bool instantiateMesh(const std::string& name, Mesh& mesh) = 0;

protected:
    friend struct std::default_delete<Loader>;
    Loader() {}
    virtual ~Loader() {}
};

}
}

#endif