#ifndef CORE_SERVER_H
#define CORE_SERVER_H

#include "define.h"
#include "error.h"

namespace core
{
    class server
    {
    public:
        virtual ~server() {}

        virtual socket_error_t start() = 0;
    
        static Scope<server> create(const char* address, const int port);
    };
}

#endif // CORE_SERVER_H
