#include "Server.h"
#include "ServerImpl.h"

namespace core
{
    Scope<Server> Server::create(const char* address, const int port)
    {
        return CreateScope<ServerImpl>(address, port);
    }
} // namespace core
