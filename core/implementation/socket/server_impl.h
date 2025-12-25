#ifndef SERVER_IMPL_H
#define SERVER_IMPL_H

#include "socket/server.h"
#include "utils/thread_pool.h"
#include <thread>

namespace core {
    class ServerImpl : public server
    {
    public:
        ServerImpl(const char* address, const int port);
        virtual ~ServerImpl();

        virtual socket_error_t start() override;

    private:
        void run_loop();
        void broadcast_message(const SocketHandle_t& sender, const char* message, const size_t length);

    private:
        bool mRunning;
        ThreadPool mThreadPool;
        endpoint_t mEndpoint;
        SocketHandle_t mHandle;
        SocketAddress_t mAddress;
        std::unordered_map<SocketHandle_t, SocketAddress_t> mClients;
    };
}

#endif // SERVER_H
