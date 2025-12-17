#ifndef SOCKET_UTILS_H
#define SOCKET_UTILS_H

#include "interface/error.h"
#include "interface/define.h"

namespace core
{
    class socket_utils
    {
    public:
        static socket_error_t set_option(SocketHandle_t socket, int option, int value);
        static socket_error_t create_address(const endpoint_t &endpoint, SocketAddress_t& outAddress);
        static socket_error_t bind(SocketHandle_t socket, const SocketAddress_t& address);
        static socket_error_t listen(SocketHandle_t socket, int backlog);
        static socket_error_t connect(SocketHandle_t socket, const SocketAddress_t& address);
    };
} // namespace core

#endif // SOCKET_UTILS_H
