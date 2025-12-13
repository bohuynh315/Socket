#include "interface/IServer.h"
#include "Server.h"

namespace core {
    Scope<IServer> IServer::create(int port)
    {
        return CreateScope<Server>(port);
    }
}
