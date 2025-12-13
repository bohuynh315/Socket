#include "interface/IClient.h"

#include "Client.h"

namespace core {
    Scope<IClient> IClient::create()
    {
        return CreateScope<Client>();
    }
}
