#ifndef CLIENT_IMPL_H
#define CLIENT_IMPL_H

#include "socket/Client.h"
#include <thread>

namespace core {
    class ClientImpl : public Client
    {
    public:
        ClientImpl(const char* address, int port);
        virtual ~ClientImpl();

        virtual socket_error_t start() override;
        virtual void stop() override;
        virtual socket_error_t register_message_handler(const message_handler_t &handler) override;

    private:
        void receive_loop();
        void send_loop();

    private:
        endpoint_t mEndpoint;
        SocketHandle_t mHandle;
        SocketAddress_t mServerAddr;

        std::atomic<bool> mSendRunning;
        std::thread mSendThread;

        std::atomic<bool> mRecvRunning;
        std::thread mReceiveThread;
        std::mutex mReceiveMutex;

        // Message handler
        std::mutex mHandlerMutex;
        message_handler_t mMessageHandler;
    };
}

#endif // CLIENT_IMPL_H
