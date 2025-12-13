#ifndef CLIENT_H
#define CLIENT_H

#include "interface/IClient.h"

namespace core {
    class Client : public IClient
    {
    public:
        Client();
        virtual ~Client();

        virtual int init() override;
        virtual int run() override;
        virtual int stop() override;

    private:
        bool running;
    };
}

#endif // CLIENT_H
