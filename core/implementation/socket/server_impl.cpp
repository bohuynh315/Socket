#include "server_impl.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "utils/socket_utils.h"
#include "logger.h"

#define BACKLOG 10 /* How many pending connections queue will hold */

namespace core
{
    ServerImpl::ServerImpl(const char* address, const int port)
        : Server()
        , mRunning(false)
        , mEndpoint{address, port}
        , mHandle(-1)
    {

    }

    ServerImpl::~ServerImpl()
    {

    }

    socket_error_t ServerImpl::start()
    {
        mRunning = true;

        socket_error_t ret = E_OK;
        struct sockaddr_in address;

        mHandle = socket(AF_INET, SOCK_STREAM, 0);
        if (mHandle < 0) {
            LOG_ERROR << "Failed to create socket";
            ret = E_FAILED_TO_CREATE_SOCKET;
            return ret;
        }

        ret = SocketUtils::create_address(mEndpoint, mAddress);
        if (ret != E_OK) {
            LOG_ERROR << "Failed to create address";
            return ret;
        }

        ret = SocketUtils::set_option(mHandle, SO_REUSEADDR, 1);
        if (ret != E_OK) {
            LOG_ERROR << "Failed to set socket options";
            return ret;
        }

        ret = SocketUtils::bind(mHandle, mAddress);
        if (ret != E_OK) {
            LOG_ERROR << "Failed to bind socket";
            return ret;
        }

        ret = SocketUtils::listen(mHandle, BACKLOG);
        if (ret != E_OK) {
            LOG_ERROR << "Failed to listen on socket";
            return ret;
        }

        mThread = std::thread([this]() {
            this->run_loop();
        });

        return E_OK;
    }

    void ServerImpl::stop()
    {
        mRunning = false;

        if (mHandle >= 0) {
            shutdown(mHandle, SHUT_RDWR);
            close(mHandle);
            mHandle = -1;
        }

        if (mThread.joinable())
        {
            mThread.join();
        }
    }

    void ServerImpl::run_loop()
    {
        while (mRunning)
        {
            struct sockaddr_in clientAddress;
            socklen_t clientAddrLen = sizeof(clientAddress);
            SocketHandle_t clientSocket = accept(mHandle, reinterpret_cast<sockaddr*>(&clientAddress), &clientAddrLen);
            if (clientSocket < 0)
            {
                LOG_ERROR << "Failed to accept client connection";
                continue;
            }

            LOG_INFO << "Client connected from "
                     << inet_ntoa(clientAddress.sin_addr)
                     << ":" << ntohs(clientAddress.sin_port)
                     << "";

            LOG_INFO << "Client connected";

            mClients[clientSocket] = clientAddress;

            SocketHandle_t sock = clientSocket;
            sockaddr_in addr = clientAddress;

            mThreadPool.enqueue_task([this, sock, addr]() {
                // Handle client communication here
                LOG_INFO << "New task for client communication";
                while(true) {
                    char buffer[1024] = {0};
                    ssize_t bytesRead = recv(sock, buffer, sizeof(buffer), 0);
                    if (bytesRead <= 0) {
                        break; // Connection closed or error
                    }
                    LOG_INFO << "Received from client ("
                              << inet_ntoa(addr.sin_addr)
                              << ":" << ntohs(addr.sin_port)
                              << "): "
                              << std::string(buffer, bytesRead) << "";

                    broadcast_message(sock, buffer, bytesRead);
                }

                mClients.erase(sock);
                shutdown(sock, SHUT_RDWR);
                close(sock);

                LOG_INFO << "Client ("
                         << inet_ntoa(addr.sin_addr)
                         << ":" << ntohs(addr.sin_port)
                         << ") has been disconnected";
            });
        }
    }

    void ServerImpl::broadcast_message(const SocketHandle_t& sender, const char* message, const size_t length)
    {
        for (const auto& client : mClients)
        {
            SocketHandle_t clientSocket = client.first;
            if (clientSocket != sender)
            {
                send(clientSocket, message, length, 0);
            }
        }
    }
} // namespace core
