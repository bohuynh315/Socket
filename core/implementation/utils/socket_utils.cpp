#include "socket_utils.h"

#include <cstdlib>
#include <arpa/inet.h>

namespace core
{
    socket_error_t SocketUtils::set_option(SocketHandle_t socket, int option, int value)
    {
        if (setsockopt(socket, SOL_SOCKET, option, &value, sizeof(value)) < 0) {
            return E_FAILED_TO_CREATE_SOCKET;
        }
        return E_OK;
    }

    socket_error_t SocketUtils::create_address(const endpoint_t &endpoint, SocketAddress_t& outAddress)
    {
        outAddress.sin_family = AF_INET;
        outAddress.sin_port = htons(endpoint.port);
        if (inet_pton(AF_INET, endpoint.ip, &outAddress.sin_addr) <= 0) {
            return E_INVALID_PARAMETER;
        }
        return E_OK;
    }

    socket_error_t SocketUtils::bind(SocketHandle_t socket, const SocketAddress_t& address)
    {
        if (::bind(socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
            return E_FAILED_TO_BIND_SOCKET;
        }
        return E_OK;
    }

    socket_error_t SocketUtils::listen(SocketHandle_t socket, int backlog)
    {
        if (::listen(socket, backlog) < 0) {
            return E_FAILED_TO_LISTEN_SOCKET;
        }
        return E_OK;
    }

    socket_error_t SocketUtils::connect(SocketHandle_t socket, const SocketAddress_t& address)
    {
        if (::connect(socket, (struct sockaddr*)&address, sizeof(address)) < 0) {
            return E_FAILED_TO_CONNECT_SOCKET;
        }
        return E_OK;
    }
} // namespace core
