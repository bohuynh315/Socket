#include "socket/server.h"
#include "server_impl.h"

namespace core
{
    Scope<server> server::create(const char* address, const int port)
    {
        return CreateScope<ServerImpl>(address, port);
    }
} // namespace core
