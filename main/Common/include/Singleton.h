#ifndef SINGLETON_H
#define SINGLETON_H

#include <stdexcept>
#include <atomic>

namespace RayWorm {
namespace Common {

template<typename T>
class Singleton {
public:
    Singleton(const Singleton& rhs) = delete;
    Singleton& operator=(const Singleton& rhs) = delete;

    Singleton(Singleton&& rhs) = delete;
    Singleton& operator=(Singleton&& rhs) = delete;

    static T& getSingleton() {
        if (ptr == nullptr) {
            throw std::runtime_error("Singleton not initialized.");
        }
        return *ptr;
    }

    Singleton() {
        if (ptr != nullptr) {
            throw std::runtime_error("Singleton can not instance twice.");
        }
        ptr = static_cast<T*>(this);
    }
    ~Singleton() {
        ptr = nullptr;
    }

private:
    static std::atomic<T*> ptr;
};

template <typename T>
std::atomic<T*> Singleton<T>::ptr(nullptr);


}
}



#endif