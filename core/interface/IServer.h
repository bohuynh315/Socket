#ifndef ISERVER_H
#define ISERVER_H

#include "Utils.h"
#include "Error.h"

namespace core {
    class IServer
    {
    public:
        virtual ~IServer() {}

        virtual error_t init() = 0;
        virtual error_t run() = 0;
        virtual error_t stop() = 0;

        // virtual int send() = 0;
    
        // virtual int onClientConnect(int clientId) = 0;
        // virtual int onClientDisconnect(int clientId) = 0;
    
        static Scope<IServer> create(int port);
    };
}

#endif // ISERVER_H
