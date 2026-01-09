#ifndef CORE_DEFINE_H
#define CORE_DEFINE_H

#include <memory>

namespace core
{
    template<typename T>
    using Scope = std::unique_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Scope<T> CreateScope(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using Ref = std::shared_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Ref<T> CreateRef(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}

#define FREE_MEMORY(memory) if (memory != nullptr) { delete memory; memory = nullptr; }

#define BIND_EVENT_FUNCTION(function) [this](auto&&... args) -> decltype(auto) \
	{ return this->function(std::forward<decltype(args)>(args)...); }

#endif // CORE_DEFINE_H
