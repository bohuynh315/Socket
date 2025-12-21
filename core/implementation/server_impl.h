#ifndef SERVER_IMPL_H
#define SERVER_IMPL_H

#include "interface/server.h"
#include "utils/thread_pool.h"
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
        void broadcast_message(const SocketHandle_t& sender, const char* message, const size_t length);

    private:
        bool mRunning;
        thread_pool mThreadPool;
        endpoint_t mEndpoint;
        SocketHandle_t mHandle;
        SocketAddress_t mAddress;
        std::unordered_map<SocketHandle_t, SocketAddress_t> mClients;
    };
}

#endif // SERVER_H
