#include "socket/server.h"
#include "logger.h"

#define SERVER_ADDRESS  "127.0.0.1"
#define SEVER_PORT      8080

int main()
{
    LOG_INFO << "Starting server at " << SERVER_ADDRESS << ":" << SEVER_PORT;

    core::Scope<core::server> server = core::server::create(SERVER_ADDRESS, SEVER_PORT);

    if (server->start() != E_OK) {
        LOG_ERROR << "Server failed to run";
        return -1;
    }

    LOG_INFO << "Server is running";
    return 0;
}
