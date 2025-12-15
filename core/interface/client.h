#ifndef CORE_ClIENT_H
#define CORE_ClIENT_H

#include "utils.h"
#include "error.h"

namespace core {
    class client
    {
    public:
        virtual ~client() {}

        virtual error_t init() = 0;
        virtual error_t start() = 0;
        virtual error_t stop() = 0;

        static Scope<client> create(const char* address, int port);

        // virtual int sendRequest(const char* request, char* response, int responseSize) = 0;
};

}

#endif // CORE_ClIENT_H