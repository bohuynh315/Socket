#include "ClientImpl.h"

#include <arpa/inet.h>
#include <unistd.h>

#include "SocketUtils.h"

namespace core {
    ClientImpl::ClientImpl(const char* address, int port)
        : Client()
        , mSendRunning(false)
        , mRecvRunning(false)
        , mEndpoint{address, port}
        , mHandle(0)
    {

    }

    ClientImpl::~ClientImpl()
    {

    }

    socket_error_t ClientImpl::start()
    {
        socket_error_t ret = E_OK;
        mSendRunning = true;
        mRecvRunning = true;
    
        // Create socket
        mHandle = socket(AF_INET, SOCK_STREAM, 0);
        if (mHandle < 0) {
            LOG_ERROR << "Failed to create socket";
            return E_FAILED_TO_CREATE_SOCKET;
        }

        // Connect to server
        ret = SocketUtils::create_address(mEndpoint, mServerAddr);
        if (ret != E_OK) {
            LOG_ERROR << "Failed to create address";
            return ret;
        }


        ret = SocketUtils::connect(mHandle, mServerAddr);
        if (ret != E_OK) {
            LOG_ERROR << "Failed to connect to server";
            return ret;
        }

        LOG_INFO << "Connected to server " << mEndpoint.ip << ":" << mEndpoint.port << '\n';

        mSendThread = std::thread([this]() {
            LOG_DEBUG << "Starting send loop thread";
            this->send_loop();
        });

        mReceiveThread = std::thread([this]() {
            LOG_DEBUG << "Starting receive loop thread";
            this->receive_loop();
        });

        return E_OK;
    }

    void ClientImpl::stop()
    {
        mSendRunning = false;
        mRecvRunning = false;

        if (mHandle >= 0) {
            shutdown(mHandle, SHUT_RDWR);
            close(mHandle);
            mHandle = -1;
        }

        if (mReceiveThread.joinable())
        {
            mReceiveThread.join();
        }

        if (mSendThread.joinable())
        {
            mSendThread.join();
        }

        LOG_INFO << "Client stopped successfully";
    }

    socket_error_t ClientImpl::register_message_handler(const message_handler_t &handler)
    {
        std::lock_guard<std::mutex> lock(mHandlerMutex);
        mMessageHandler = handler;

        return E_OK;
    }

    void ClientImpl::receive_loop()
    {
        while (mRecvRunning)
        {
            LOG_INFO << "Waiting to receive data from server...";
            char buffer[1024] = {0};
            ssize_t bytesRead = recv(mHandle, buffer, sizeof(buffer), 0);
            if (bytesRead <= 0) {
                LOG_ERROR << "Server connection closed or error occurred";
                break; // Connection closed or error
            }

            std::lock_guard<std::mutex> lock(this->mHandlerMutex);
            if (this->mMessageHandler) {
                this->mMessageHandler(buffer, bytesRead);
            }
        }
    }

    void ClientImpl::send_loop()
    {
        while (mSendRunning)
        {
            LOG_INFO << "Sending heartbeat to server...";
            const char* heartbeat = "HEARTBEAT";
            
            size_t ret = send(mHandle, heartbeat, strlen(heartbeat), 0);
            if (ret < 0) {
                LOG_ERROR << "Failed to send heartbeat to server";
                break;
            }
            LOG_INFO << "Sent heartbeat to server";
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }

} // namespace core
