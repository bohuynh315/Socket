#ifndef CORE_UTILS_H
#define CORE_UTILS_H

#include "interface/error.h"
#include "interface/define.h"

namespace core
{
    namespace utils
    {
        socket_error_t bind(SocketHandle_t socket, const SocketAddress_t& address);
        socket_error_t listen(SocketHandle_t socket, int backlog);
        socket_error_t connect(SocketHandle_t socket, const SocketAddress_t& address);
        socket_error_t create_address(const endpoint_t &endpoint, SocketAddress_t& outAddress);
        socket_error_t set_option(SocketHandle_t socket, int option, int value);
    } // namespace utils
} // namespace core

#endif // CORE_UTILS_H
