#include "server_impl.h"

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "utils.h"

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
    }

    socket_error_t server_impl::start()
    {
        mRunning = true;

        socket_error_t ret = E_OK;
        struct sockaddr_in address;

        mHandle = socket(AF_INET, SOCK_STREAM, 0);
        if (mHandle < 0) {
            std::cout << "Failed to create socket\n";
            ret = E_FAILED_TO_CREATE_SOCKET;
            return ret;
        }

        ret = utils::create_address(mEndpoint, mAddress);
        if (ret != E_OK) {
            std::cout << "Failed to create address\n";
            return ret;
        }

        ret = utils::set_option(mHandle, SO_REUSEADDR, 1);
        if (ret != E_OK) {
            std::cout << "Failed to set socket options\n";
            return ret;
        }

        ret = utils::bind(mHandle, mAddress);
        if (ret != E_OK) {
            std::cout << "Failed to bind socket\n";
            return ret;
        }

        ret = utils::listen(mHandle, BACKLOG);
        if (ret != E_OK) {
            std::cout << "Failed to listen on socket\n";
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
        // Placeholder for server main loop logic
        while (mRunning)
        {
            struct sockaddr_in clientAddress;
            socklen_t clientAddrLen = sizeof(clientAddress);
            SocketHandle_t clientSocket = accept(mHandle, (struct sockaddr *)&clientAddress, &clientAddrLen);
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
