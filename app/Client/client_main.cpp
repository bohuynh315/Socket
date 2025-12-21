#include "interface/client.h"
#include "interface/logger.h"

#define SERVER_ADDRESS  "127.0.0.1"
#define SERVER_PORT     8080

void on_message_received(const char* message, const size_t length)
{
    LOG_INFO << "Received from server: " << std::string(message, length) << '\n';
};

int main()
{
    core::Scope<core::client> client = core::client::create(SERVER_ADDRESS, SERVER_PORT);
    client->register_message_handler(on_message_received);

    if (client->start() != E_OK) {
        LOG_ERROR << "Client failed to run";
        return -1;
    }

    LOG_INFO << "Client is running";
    return 0;
}