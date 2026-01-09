#ifndef CORE_SERVER_H
#define CORE_SERVER_H

#include "Base.h"
#include "Error.h"

namespace core
{
    class Server
    {
    public:
        virtual ~Server() {}

        virtual socket_error_t start() = 0;
        virtual void stop() = 0;
    
        static Scope<Server> create(const char* address, const int port);
    };
}

#endif // CORE_SERVER_H
