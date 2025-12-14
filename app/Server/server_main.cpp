#include "interface/server.h"
#include <iostream>

#define SEVER_PORT 8080

int main()
{
    core::Scope<core::server> server = core::server::create(SEVER_PORT);

    if (server->init() != E_OK) {
        std::cout << "Server initialization failed\n";
        return -1;
    }

    if (server->start() != E_OK) {
        std::cout << "Server failed to run\n";
        return -1;
    }

    return 0;
}