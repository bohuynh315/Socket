#ifndef CORE_SERVER_H
#define CORE_SERVER_H

#include "utils.h"
#include "error.h"

namespace core {
    class server
    {
    public:
        virtual ~server() {}

        virtual error_t init() = 0;
        virtual error_t start() = 0;
        virtual error_t stop() = 0;
    
        static Scope<server> create(const char* address, const int port);
    };
}

#endif // CORE_SERVER_H
