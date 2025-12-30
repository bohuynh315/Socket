#ifndef CORE_ClIENT_H
#define CORE_ClIENT_H

#include "define.h"
#include "error.h"

namespace core
{
    class Client
    {
    public:
        virtual ~Client() {}

        virtual socket_error_t start() = 0;
        virtual void stop() = 0;
        virtual socket_error_t register_message_handler(const message_handler_t &handler) = 0;

        static Scope<Client> create(const char* address, int port);
    };
}

#endif // CORE_ClIENT_H
