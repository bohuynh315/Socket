#ifndef SERVER_H
#define SERVER_H

#include "interface/IServer.h"
#include <thread>

namespace core {
    class Server : public IServer
    {
    public:
        Server(const int port);
        virtual ~Server();

        virtual error_t init() override;
        virtual error_t run() override;
        virtual error_t stop() override;

    private:
        bool mRunning;
        int mPort;
        std::thread mThread;
        SocketHandle_t mHandle;
        SocketAddress_t mAddress;
    };
}

#endif // SERVER_H
