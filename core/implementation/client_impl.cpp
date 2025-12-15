#include "client_impl.h"

#include <arpa/inet.h>
#include <iostream>

namespace core {
    client_impl::client_impl(const char* address, int port)
        : running(false)
        , mAddressStr(address)
        , mPort(port)
        , mHandle(0)
    {

    }

    client_impl::~client_impl()
    {

    }

    error_t client_impl::init()
    {
        mHandle = socket(AF_INET, SOCK_STREAM, 0);
        if (mHandle < 0) {
            std::cout << "Failed to create socket\n";
            return E_FAILED_TO_CREATE_SOCKET;
        }

        mServerAddr.sin_family = AF_INET;
        mServerAddr.sin_port = htons(mPort);

        if (inet_pton(AF_INET, mAddressStr, &mServerAddr.sin_addr) <= 0) {
            std::cout << "Invalid address/ Address not supported \n";
            return E_INVALID_PARAMETER;
        }
    
        return E_OK;
    }

    error_t client_impl::start()
    {
        running = true;

        if (connect(mHandle, (struct sockaddr*)&mServerAddr, sizeof(mServerAddr)) < 0) {
            return E_FAILED_TO_BIND_SOCKET;
        }

        return E_OK;
    }

    error_t client_impl::stop()
    {
        running = false;

        return E_OK;
    }
} // namespace core
