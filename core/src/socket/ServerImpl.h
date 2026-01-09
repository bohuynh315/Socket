#ifndef SERVER_IMPL_H
#define SERVER_IMPL_H

#include "socket/Server.h"
#include "utils/ThreadPool.h"
#include <thread>

namespace core
{
    class ServerImpl : public Server
    {
    public:
        ServerImpl(const char *address, const int port);
        virtual ~ServerImpl();

        virtual socket_error_t start() override;
        virtual void stop() override;

    private:
        void run_loop();
        void broadcast_message(const SocketHandle_t &sender, const char *message, const size_t length);

    private:
        std::thread mThread;
        std::atomic<bool> mRunning;
        ThreadPool mThreadPool;
        endpoint_t mEndpoint;
        SocketHandle_t mHandle;
        SocketAddress_t mAddress;
        std::unordered_map<SocketHandle_t, SocketAddress_t> mClients;
    };
}

#endif // SERVER_H
