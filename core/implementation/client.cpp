#include "interface/client.h"
#include "client_impl.h"

namespace core {
    Scope<client> client::create(const char* address, int port)
    {
        return CreateScope<client_impl>(address, port);
    }
} // namespace core
