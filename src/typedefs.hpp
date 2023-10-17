#ifndef __TYPEDEFS_HPP__
#define __TYPEDEFS_HPP__

#include <memory>

namespace prim
{
    template<class T>
    using unPtr = std::unique_ptr<T>;
    template<class T>
    using shPtr = std::shared_ptr<T>;
}

#endif // __TYPEDEFS_HPP__