#include "interface/client.h"
#include "interface/logger.h"

#define SERVER_ADDRESS  "127.0.0.1"
#define SERVER_PORT     8080

int main()
{
    core::Scope<core::client> client = core::client::create(SERVER_ADDRESS, SERVER_PORT);

    if (client->start() != E_OK) {
        LOG_ERROR << "Client failed to run";
        return -1;
    }

    return 0;
}