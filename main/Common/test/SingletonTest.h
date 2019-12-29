#ifndef SINGLETON_TEST_H
#define SINGLETON_TEST_H

#include <Singleton.h>

namespace RayWorm {
namespace Common {

class SingletonTest : public Singleton<SingletonTest> {
public:
    SingletonTest() {}
    ~SingletonTest() {}

    void testValue(size_t& t);
};

}
}


#endif