#include "client_impl.h"

#include <arpa/inet.h>

#include "utils/socket_utils.h"
#include "interface/logger.h"

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

        return E_OK;
    }

} // namespace core
