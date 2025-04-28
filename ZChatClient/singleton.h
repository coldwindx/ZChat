#ifndef SINGLETON_H
#define SINGLETON_H

#include <memory>
#include <mutex>

template<typename T>
class Singleton{
protected:
    Singleton() = default;
    Singleton(const Singleton<T> &) = delete;
    Singleton& operator=(const Singleton<T> &) = delete;

    static std::shared_ptr<T> instance;
public:
    static sd::shared_ptr<T> GetInstance(){
        static std::once_flag s_flag;
        std::call_once(s_flag, [&](){ instance = shared_ptr<T>(new T) });
        return instance;
    }
};

template<typename T>
std::shared_ptr<T> Singleton<T>::instance = nullptr;
#endif // SINGLETON_H
