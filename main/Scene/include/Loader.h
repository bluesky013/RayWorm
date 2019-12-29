

#ifndef LOADER_H
#define LOADER_H

#include <string>

namespace RayWorm {
namespace Scene {

class Loader {
public:
    static Loader* loadAsset(const std::string& url);

    virtual bool load(const std::string& url, const std::string& ext) = 0;

protected:
    friend struct std::default_delete<Loader>;
    Loader() {}
    virtual ~Loader() {}
};

}
}

#endif