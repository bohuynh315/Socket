#ifndef CLIENT_IMPL_H
#define CLIENT_IMPL_H

#include "interface/client.h"

namespace core {
    class client_impl : public client
    {
    public:
        client_impl();
        virtual ~client_impl();

        virtual error_t init() override;
        virtual error_t start() override;
        virtual error_t stop() override;

    private:
        bool running;
    };
}

#endif // CLIENT_IMPL_H
