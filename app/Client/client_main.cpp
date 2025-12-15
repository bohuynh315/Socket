#include "interface/client.h"
#include <iostream>

#define SERVER_ADDRESS  "127.0.0.1"
#define SERVER_PORT     8080

int main()
{
    core::Scope<core::client> client = core::client::create(SERVER_ADDRESS, SERVER_PORT);

    if (client->init() != E_OK) {
        std::cout << "Client initialization failed\n";
        return -1;
    }

    if (client->start() != E_OK) {
        std::cout << "Client failed to run\n";
        return -1;
    }

    return 0;
}