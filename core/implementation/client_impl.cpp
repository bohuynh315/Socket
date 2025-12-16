#include "client_impl.h"

#include <arpa/inet.h>
#include <iostream>

#include "utils.h"

namespace core {
    client_impl::client_impl(const char* address, int port)
        : client()
        , running(false)
        , mEndpoint{address, port}
        , mHandle(0)
    {

    }

    client_impl::~client_impl()
    {

    }

    socket_error_t client_impl::start()
    {
        socket_error_t ret = E_OK;
        running = true;

        mHandle = socket(AF_INET, SOCK_STREAM, 0);
        if (mHandle < 0) {
            std::cout << "Failed to create socket\n";
            return E_FAILED_TO_CREATE_SOCKET;
        }

        // Connect to server
        ret = utils::create_address(mEndpoint, mServerAddr);
        if (ret != E_OK) {
            std::cout << "Failed to create address\n";
            return ret;
        }

        ret = utils::connect(mHandle, mServerAddr);
        if (ret != E_OK) {
            std::cout << "Failed to connect to server\n";
            return ret;
        }

        return E_OK;
    }

} // namespace core
