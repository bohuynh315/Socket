#ifndef IClIENT_H
#define IClIENT_H

#include "Utils.h"

namespace core {
    class IClient
    {
    public:
        virtual ~IClient() {}

        virtual int init() = 0;
        virtual int run() = 0;
        virtual int stop() = 0;

        static Scope<IClient> create();

        // virtual int sendRequest(const char* request, char* response, int responseSize) = 0;
};

}

#endif // IClIENT_H