#include "server_impl.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "utils/socket_utils.h"
#include "interface/logger.h"

#define BACKLOG 10 /* How many pending connections queue will hold */

namespace core
{
    server_impl::server_impl(const char* address, const int port)
        : server()
        , mRunning(false)
        , mEndpoint{address, port}
        , mHandle(0)
    {

    }

    server_impl::~server_impl()
    {
        if (mThread.joinable())
        {
            mThread.join();
        }
        close(mHandle);
    }

    socket_error_t server_impl::start()
    {
        mRunning = true;

        socket_error_t ret = E_OK;
        struct sockaddr_in address;

        mHandle = socket(AF_INET, SOCK_STREAM, 0);
        if (mHandle < 0) {
            LOG_ERROR << "Failed to create socket\n";
            ret = E_FAILED_TO_CREATE_SOCKET;
            return ret;
        }

        ret = socket_utils::create_address(mEndpoint, mAddress);
        if (ret != E_OK) {
            LOG_ERROR << "Failed to create address\n";
            return ret;
        }

        ret = socket_utils::set_option(mHandle, SO_REUSEADDR, 1);
        if (ret != E_OK) {
            LOG_ERROR << "Failed to set socket options\n";
            return ret;
        }

        ret = socket_utils::bind(mHandle, mAddress);
        if (ret != E_OK) {
            LOG_ERROR << "Failed to bind socket\n";
            return ret;
        }

        ret = socket_utils::listen(mHandle, BACKLOG);
        if (ret != E_OK) {
            LOG_ERROR << "Failed to listen on socket\n";
            return ret;
        }

        mThread = std::thread([this]() {
            this->run_loop();
        });
        // mThread.detach();

        return E_OK;
    }

    void server_impl::run_loop()
    {
        while (mRunning)
        {
            struct sockaddr_in clientAddress;
            socklen_t clientAddrLen = sizeof(clientAddress);
            SocketHandle_t clientSocket = accept(mHandle, (struct sockaddr *)&clientAddress, &clientAddrLen);
            if (clientSocket < 0)
            {
                LOG_ERROR << "Failed to accept client connection\n";
                continue;
            }

            LOG_INFO << "Client connected from "
                     << inet_ntoa(clientAddress.sin_addr)
                     << ":" << ntohs(clientAddress.sin_port)
                     << "\n";

            LOG_INFO << "Client connected\n";

            mThreadPool.enqueue_task([&]() {
                // Handle client communication here
                while(true) {
                    char buffer[1024] = {0};
                    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
                    if (bytesRead <= 0) {
                        break; // Connection closed or error
                    }
                    LOG_ERROR << "Received from client: " << std::string(buffer, bytesRead) << "\n";

                    // Echo back to client
                    // send(clientSocket, buffer, bytesRead, 0);
                }

                close(clientSocket);
                LOG_INFO << "Client ("
                         << inet_ntoa(clientAddress.sin_addr)
                         << ":" << ntohs(clientAddress.sin_port)
                         << ") has been disconnected\n";
            });
        }
    }
} // namespace core
