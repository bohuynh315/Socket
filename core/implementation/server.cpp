#include "socket/server.h"
#include "server_impl.h"

namespace core
{
    Scope<server> server::create(const char* address, const int port)
    {
        return CreateScope<server_impl>(address, port);
    }
} // namespace core
