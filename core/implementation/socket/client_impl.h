#ifndef CLIENT_IMPL_H
#define CLIENT_IMPL_H

#include "socket/client.h"
#include <thread>

namespace core {
    class ClientImpl : public client
    {
    public:
        ClientImpl(const char* address, int port);
        virtual ~ClientImpl();

        virtual socket_error_t start() override;
        virtual socket_error_t register_message_handler(const message_handler_t &handler) override;

    private:
        void receive_loop();
        void send_loop();

    private:
        bool mRunning;
        endpoint_t mEndpoint;
        std::thread mThread;
        SocketHandle_t mHandle;
        SocketAddress_t mServerAddr;

        std::thread mReceiveThread;
        std::mutex mReceiveMutex;

        // Message handler
        std::mutex mHandlerMutex;
        message_handler_t mMessageHandler;
    };
}

#endif // CLIENT_IMPL_H
