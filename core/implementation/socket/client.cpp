#include "socket/client.h"
#include "client_impl.h"

namespace core
{
    Scope<Client> Client::create(const char* address, int port)
    {
        return CreateScope<ClientImpl>(address, port);
    }
} // namespace core
