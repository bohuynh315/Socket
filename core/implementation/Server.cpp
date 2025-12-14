#include "interface/server.h"
#include "server_impl.h"

namespace core {
    Scope<server> server::create(int port)
    {
        return CreateScope<server_impl>(port);
    }
} // namespace core
