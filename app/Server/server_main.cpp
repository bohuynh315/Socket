#include "interface/IServer.h"
#include <iostream>

int main()
{
    const int port = 8080;
    core::Scope<core::IServer> server = core::IServer::create(port);

    if (server->init() != E_OK) {
        std::cout << "Server initialization failed\n";
        return -1;
    }

    if (server->run() != E_OK) {
        std::cout << "Server failed to run\n";
        return -1;
    }

    // For demonstration purposes, we'll just stop the server immediately.
    if (server->stop() != E_OK) {
        std::cout << "Server failed to stop\n";
        return -1;
    }

    return 0;
}