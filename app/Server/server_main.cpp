#include "interface/server.h"
#include <iostream>

#define SERVER_ADDRESS  "127.0.0.1"
#define SEVER_PORT      8080

int main()
{
    core::Scope<core::server> server = core::server::create(SERVER_ADDRESS, SEVER_PORT);

    if (server->start() != E_OK) {
        std::cout << "Server failed to run\n";
        return -1;
    }

    return 0;
}