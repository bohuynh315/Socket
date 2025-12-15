#ifndef CORE_UTILS_H
#define CORE_UTILS_H

#include <memory>
#include <netinet/in.h>

typedef int SocketHandle_t;
typedef struct sockaddr_in SocketAddress_t;

namespace core {
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

#endif // CORE_UTILS_H
