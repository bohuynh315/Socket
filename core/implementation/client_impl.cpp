#include "client_impl.h"

#include <arpa/inet.h>
#include <unistd.h>

#include "utils/socket_utils.h"
#include "interface/logger.h"

namespace core {
    client_impl::client_impl(const char* address, int port)
        : client()
        , mRunning(false)
        , mEndpoint{address, port}
        , mHandle(0)
    {

    }

    client_impl::~client_impl()
    {
        mRunning = false;

        if (mReceiveThread.joinable())
        {
            mReceiveThread.join();
        }

        close(mHandle);
    }

    socket_error_t client_impl::start()
    {
        socket_error_t ret = E_OK;
        mRunning = true;

        mHandle = socket(AF_INET, SOCK_STREAM, 0);
        if (mHandle < 0) {
            LOG_ERROR << "Failed to create socket\n";
            return E_FAILED_TO_CREATE_SOCKET;
        }

        // Connect to server
        ret = socket_utils::create_address(mEndpoint, mServerAddr);
        if (ret != E_OK) {
            LOG_ERROR << "Failed to create address\n";
            return ret;
        }


        ret = socket_utils::connect(mHandle, mServerAddr);
        if (ret != E_OK) {
            LOG_ERROR << "Failed to connect to server\n";
            return ret;
        }

        LOG_INFO << "Connected to server " << mEndpoint.ip << ":" << mEndpoint.port << '\n';

        mReceiveThread = std::thread([this]() {
            this->receive_loop();
        });

        send_loop();

        return E_OK;
    }

    socket_error_t client_impl::register_message_handler(const message_handler_t &handler)
    {
        std::lock_guard<std::mutex> lock(mHandlerMutex);
        mMessageHandler = handler;

        return E_OK;
    }

    void client_impl::receive_loop()
    {
        while (mRunning)
        {
            char buffer[1024] = {0};
            ssize_t bytesRead = recv(this->mHandle, buffer, sizeof(buffer), 0);
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

    void client_impl::send_loop()
    {
        // Sending loop (for demonstration, sending a heartbeat every 5 seconds)
        while (this->mRunning)
        {
            const char* heartbeat = "HEARTBEAT";
            
            size_t ret = send(this->mHandle, heartbeat, strlen(heartbeat), 0);
            if (ret < 0) {
                LOG_ERROR << "Failed to send heartbeat to server";
                break;
            }
            LOG_INFO << "Sent heartbeat to server\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }

} // namespace core
