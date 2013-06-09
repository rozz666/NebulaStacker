#ifndef NEBULA_CHECKEDPTR_HPP
#define NEBULA_CHECKEDPTR_HPP
#include <stdexcept>

namespace Nebula
{

struct NullPointer : std::out_of_range
{
    explicit NullPointer(const std::string& message) : std::out_of_range(message) { }
};

template <typename T>
class CheckedPtr
{
public:
    CheckedPtr() : ptr(nullptr) { }
    CheckedPtr(T *ptr) : ptr(ptr) { }
    T& operator*() const
    {
        if (!ptr)
            throw NullPointer("operator*: CheckedPtr is null");
        return *ptr;
    }
    T *operator->() const
    {
        if (!ptr)
            throw NullPointer("operator->: CheckedPtr is null");
        return ptr;
    }
private:
    T *ptr;
};

}

#endif // NEBULA_CHECKEDPTR_HPP
