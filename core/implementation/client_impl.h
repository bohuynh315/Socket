#ifndef CLIENT_IMPL_H
#define CLIENT_IMPL_H

#include "interface/client.h"
#include <thread>

namespace core {
    class client_impl : public client
    {
    public:
        client_impl(const char* address, int port);
        virtual ~client_impl();

        virtual socket_error_t start() override;

    private:
        bool running;
        endpoint_t mEndpoint;
        std::thread mThread;
        SocketHandle_t mHandle;
        SocketAddress_t mServerAddr;

    };
}

#endif // CLIENT_IMPL_H
