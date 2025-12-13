#include "Client.h"

namespace core {
    Client::Client()
        : running(false)
    {

    }

    Client::~Client()
    {

    }

    int Client::init()
    {
    
        return 0;
    }

    int Client::run()
    {
        running = true;

        return 0;
    }

    int Client::stop()
    {
        running = false;

        return 0;
    }
} // namespace core
