#include "Client.h"
#include "ClientImpl.h"

namespace core
{
    Scope<Client> Client::create(const char* address, int port)
    {
        return CreateScope<ClientImpl>(address, port);
    }
} // namespace core
