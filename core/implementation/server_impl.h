#ifndef SERVER_IMPL_H
#define SERVER_IMPL_H

#include "interface/server.h"
#include <thread>

namespace core {
    class server_impl : public server
    {
    public:
        server_impl(const char* address, const int port);
        virtual ~server_impl();

        virtual socket_error_t start() override;

    private:
        void run_loop();

    private:
        bool mRunning;
        endpoint_t mEndpoint;
        std::thread mThread;
        SocketHandle_t mHandle;
        SocketAddress_t mAddress;
    };
}

#endif // SERVER_H
