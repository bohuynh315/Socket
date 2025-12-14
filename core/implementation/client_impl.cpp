#include "client_impl.h"

namespace core {
    client_impl::client_impl()
        : running(false)
    {

    }

    client_impl::~client_impl()
    {

    }

    error_t client_impl::init()
    {
    
        return E_OK;
    }

    error_t client_impl::start()
    {
        running = true;

        return E_OK;
    }

    error_t client_impl::stop()
    {
        running = false;

        return E_OK;
    }
} // namespace core
