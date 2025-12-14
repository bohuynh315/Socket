#include "interface/client.h"
#include <iostream>

int main()
{
    core::Scope<core::client> client = core::client::create();

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