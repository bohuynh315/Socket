#ifndef CORE_SOCKET_UTILS_H
#define CORE_SOCKET_UTILS_H

#include "Error.h"
#include "Define.h"

namespace core
{
    class SocketUtils
    {
    public:
        static socket_error_t set_option(SocketHandle_t socket, int option, int value);
        static socket_error_t create_address(const endpoint_t &endpoint, SocketAddress_t& outAddress);
        static socket_error_t bind(SocketHandle_t socket, const SocketAddress_t& address);
        static socket_error_t listen(SocketHandle_t socket, int backlog);
        static socket_error_t connect(SocketHandle_t socket, const SocketAddress_t& address);
    };
} // namespace core

#endif // CORE_SOCKET_UTILS_H
