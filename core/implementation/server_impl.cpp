#include "server_impl.h"

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BACKLOG 10 /* How many pending connections queue will hold */

namespace core
{
    server_impl::server_impl(const int port)
        : mRunning(false)
        , mPort(port)
        , mHandle(0)
    {
        mAddress.sin_family = AF_INET;
        mAddress.sin_addr.s_addr = INADDR_ANY;
        mAddress.sin_port = htons(mPort);
    }

    server_impl::~server_impl()
    {
        if (mThread.joinable())
        {
            mThread.join();
        }
    }

    error_t server_impl::init()
    {
        error_t ret = E_OK;
        struct sockaddr_in address;

        mHandle = socket(AF_INET, SOCK_STREAM, 0);
        if (mHandle < 0) {
            std::cout << "Failed to create socket\n";
            ret = E_FAILED_TO_CREATE_SOCKET;
            return ret;
        }

        int opt = 1;
        if (setsockopt(mHandle, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
            std::cout << "Failed to set socket options\n";
            return E_FAILED_TO_CREATE_SOCKET;
        }

        if (bind(mHandle, (struct sockaddr *)&mAddress, sizeof(mAddress)) < 0) {
            std::cout << "Failed to bind socket\n";
            return E_FAILED_TO_BIND_SOCKET;
        }

        if (listen(mHandle, BACKLOG) < 0) {
            std::cout << "Failed to listen on socket\n";
            return E_FAILED_TO_LISTEN_SOCKET;
        }

        return E_OK;
    }

    error_t server_impl::start()
    {
        mRunning = true;

        if (mHandle <= 0) {
            std::cout << "Socket is not initialized\n";
            return E_FAILED_TO_CREATE_SOCKET;
        }

        mThread = std::thread([this]() {
            this->runLoop();
        });
        // mThread.detach();

        return E_OK;
    }

    error_t server_impl::stop()
    {
        mRunning = false;

        return E_OK;
    }

    void server_impl::runLoop()
    {
        // Placeholder for server main loop logic
        while (mRunning)
        {
            struct sockaddr_in clientAddress;
            socklen_t clientAddrLen = sizeof(clientAddress);
            SocketHandle_t clientSocket = accept(mHandle, (struct sockaddr *)&mAddress, &clientAddrLen);
            if (clientSocket < 0)
            {
                std::cout << "Failed to accept client connection\n";
                continue;
            }

            std::cout << "Client connected from "
                      << inet_ntoa(clientAddress.sin_addr)
                      << ":" << ntohs(clientAddress.sin_port)
                      << "\n";

            std::cout << "Client connected\n";
            // Here you would typically create a Client instance and handle communication
            // For simplicity, we just close the socket immediately
            close(clientSocket);
        }
    }
} // namespace core
