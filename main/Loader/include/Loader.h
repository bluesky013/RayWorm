

#ifndef LOADER_H
#define LOADER_H

#include <string>

namespace RayWorm {
namespace Loader {

class Loader {
public:
    virtual ~Loader() {}

    static Loader* loadAsset(const std::string& url);

    virtual bool load(const std::string& url, const std::string& ext) = 0;

protected:
    Loader() {}
};

}
}

#endif