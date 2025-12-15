#ifndef CLIENT_IMPL_H
#define CLIENT_IMPL_H

#include "interface/client.h"
#include <thread>

namespace core {
    class client_impl : public client
    {
    public:
        client_impl(const char* address = "", int port = 0);
        virtual ~client_impl();

        virtual error_t init() override;
        virtual error_t start() override;
        virtual error_t stop() override;

    private:
        bool running;
        const char* mAddressStr;
        int mPort;
        std::thread mThread;
        SocketHandle_t mHandle;
        SocketAddress_t mServerAddr;

    };
}

#endif // CLIENT_IMPL_H
