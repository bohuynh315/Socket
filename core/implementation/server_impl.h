#ifndef SERVER_IMPL_H
#define SERVER_IMPL_H

#include "interface/server.h"
#include <thread>

namespace core {
    class server_impl : public server
    {
    public:
        server_impl(const int port);
        virtual ~server_impl();

        virtual error_t init() override;
        virtual error_t start() override;
        virtual error_t stop() override;

    private:
        void runLoop();

    private:
        bool mRunning;
        int mPort;
        std::thread mThread;
        SocketHandle_t mHandle;
        SocketAddress_t mAddress;
    };
}

#endif // SERVER_H
