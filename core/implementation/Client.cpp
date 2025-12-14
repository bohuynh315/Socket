#include "interface/client.h"
#include "client_impl.h"

namespace core {
    Scope<client> client::create()
    {
        return CreateScope<client_impl>();
    }
} // namespace core
